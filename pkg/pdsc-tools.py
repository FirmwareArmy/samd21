import sys
from lxml import etree
from ruamel.yaml import YAML
from ruamel.yaml.scanner import ScannerError
import os
import re

yaml = YAML()
yaml.indent(mapping=2, sequence=4, offset=2)
yaml.allow_duplicate_keys = False
yaml.explicit_start = False

def main():

    if len(sys.argv)!=2:
        print("usage: pdsc-tool <pdsc file>", file=sys.stderr)
        exit(1)
        
    pdsc = sys.argv[1]
    output = os.path.abspath(os.path.join(os.path.dirname(sys.argv[0]), '..'))
    
    # open pdsc file
    tree = etree.parse(pdsc).getroot()

    # open army.toml
    with open("army.yaml", "r") as f:
        try:
            config = yaml.load(f)
        except ScannerError as e:
            print(
                'Error parsing yaml of configuration file '
                '{}: {}'.format(
                    e.problem_mark,
                    e.problem,
                )
            )
            sys.exit(1)
    config["archs"] = []
    config["profiles"] = []

    # cmake files
    cpu_cmake = {}
    mpu_cmake = {}
    
#     requires = {'Dvendor': 'ARM:82', 'Dname': 'ARMCM7*'}
#     a = get_el_by_condition(tree, requires)
#     while a is not None:
#         print(a.tag, a.attrib, file=sys.stderr)
#         a = get_el_by_condition(tree, requires, a)
#     exit(1)
    
    profiles = {}
    
    # parse devices
    families = tree.xpath("//devices/family")
    for family in families:
        print(family.get("Dfamily"))
        
        devices = family.xpath('device')
        for device in devices:
            print(f'    {device.get("Dname")}')
            
            processor = device.xpath("processor")[0]
            
            name = device.get("Dname").replace("AT", "")
            cpu = processor.get("Dcore")

            # add target
            config["archs"].append({
                "name": name,
                "cpu": to_gcc_name(cpu),
                "cpu_definition": f"cmake/{name}.cmake",
                "mpu": name,
                "mpu_definition": f"cmake/{name.lower()}.cmake",
            })
            
            # add profiles
            config["profiles"].append(name)
            
            # add cpu cmake file
            cpu_cmake[name] = {
                "set": {},
                "defines": {},
                "link": []
                }
            
            profiles[name] = {
                'cpu': to_gcc_name(cpu),
                'family': family.get("Dfamily")
            }
            # add mpu cmake file
            mpu_cmake[name] = {
                "set": {},
                "sources": [],
                "include_directories": [],
                "defines": {},
                "link": []
                }

            for compile in device.xpath("compile"):
                header = compile.get("header")
                header_path = f"{os.path.dirname(header)}"
                 
                if header_path not in mpu_cmake[name]["include_directories"]:
                    mpu_cmake[name]["include_directories"].append(header_path)
                define = compile.get("define")
                if define not in mpu_cmake[name]["defines"]:
                    cpu_cmake[name]["defines"][define] = ""

    print("\nAdd startup scripts:")
    # add startup scripts
    components = tree.xpath("//components/component")
    for component in components:
        cclass = component.get("Cclass")
        cgroup = component.get("Cgroup")
        cvariant = component.get("Cvariant")
        condition = component.get("condition")
        if cclass=="Device" and cgroup=="Startup":# and cvariant=="C Startup":
            print(f"{condition}")
            devices = get_devices(tree, condition)
#             print("---", devices)
            for device in devices:
                device = device.replace("AT", "")
                print(f"  {device}")
                files = component.xpath("files/file")
                for file in files:
                    category = file.get("category")
                    if category=="include":
                        if file.get("name") not in mpu_cmake[device]["include_directories"]:
                            mpu_cmake[device]["include_directories"].append(file.get("name"))
                    elif category=="source":
                        if file.get("condition")=="GCC Exe" and file.get("name") not in mpu_cmake[device]["sources"]:
                            mpu_cmake[device]["sources"].append(file.get("name"))
                    elif category=="linkerScript" and file.get("condition")=="GCC Exe" and file.get("name") not in cpu_cmake[device]["link"]:
                        cpu_cmake[device]["link"].append(file.get("name"))
            
    # write army.toml
    with open("army.yaml", "w") as f:
        yaml.dump(config, f)

    # write cpu cmake files
    for file in cpu_cmake:
        content = cpu_cmake[file]
        with open(f"cmake/{file.upper()}.cmake", "w") as f:
            f.write('if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")\n')
            f.write('    set(compiler "gcc")\n')
            f.write('elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")\n')
            f.write('    set(compiler "clang")\n')
            f.write('else()\n')
            f.write('    message(FATAL, "unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")\n')
            f.write('endif()\n')
                         
            for set in content["set"]:
                set_content = content["set"][set]
                f.write(f'set({set} "{set_content}")\n')
            f.write("\n")
             
            for define in content["defines"]:
                if content["defines"][define]=="":
                    f.write(f'set(COMMON_FLAGS "'+'${COMMON_FLAGS}'+f' -D{define}")\n')
                else:
                    f.write(f'set(COMMON_FLAGS "'+'${COMMON_FLAGS}'+f' -D{define}")\n')
            f.write("\n")
 
            for link in content["link"]:
                link = link.replace("gcc", "${compiler}")
                f.write(f'set(LINKER_FLAGS "'+'${LINKER_FLAGS}'+' -T ${PACKAGE_PATH}/'+f'dfp/{link}")\n')
            f.write("\n")

    # write cpu cmake files
    for file in mpu_cmake:
        content = mpu_cmake[file]
        with open(f"cmake/{file.lower()}.cmake", "w") as f:
            f.write('if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")\n')
            f.write('    set(compiler "gcc")\n')
            f.write('elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")\n')
            f.write('    set(compiler "clang")\n')
            f.write('else()\n')
            f.write('    message(FATAL, "unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")\n')
            f.write('endif()\n')
              
            for set in content["set"]:
                set_content = content["set"][set]
                f.write(f'set({set} "{set_content}")\n')
            f.write("\n")
              
            for define in content["defines"]:
                if content["defines"][define]=="":
                    f.write(f'set(COMMON_FLAGS "'+'${COMMON_FLAGS}'+f' -D{define}")\n')
                else:
                    f.write(f'set(COMMON_FLAGS "'+'${COMMON_FLAGS}'+f' -D{define}")\n')
            f.write("\n")
              
            f.write("list(APPEND sources\n")
            for source in content["sources"]:
                source = source.replace("gcc", "${compiler}")
                f.write("    ${PACKAGE_PATH}/"+f'dfp/{source}\n')
            f.write(")\n\n")
  
            f.write("include_directories(\n")
            for include in content["include_directories"]:
                source = source.replace("gcc", "${compiler}")
                f.write("    ${PACKAGE_PATH}/"+f'dfp/{include}\n')
            f.write(")\n\n")
  
            for link in content["link"]:
                link = link.replace("gcc", "${compiler}")
                f.write(f'set(LINKER_FLAGS "'+'${LINKER_FLAGS}'+' -T ${PACKAGE_PATH}/'+f'dfp/{link}")\n')
            f.write("\n")
    
    # write profiles
    for profile in profiles:
        content = profiles[profile]
            
        with open(f"profile/{profile}.yaml", "w") as f:
            p = {
                "arch": {
                    "name": profile,
                    "family": content['family'],
                    "cpu": content['cpu'],
                    "package": "samd21",
                    "version": config['version']
                }
            }
            yaml.dump(p, f)
            
 
    # create core.h
    with open(f"src/core++/core.h", "w") as f:
        f.write("#pragma once\n")
        f.write("\n")
        f.write("#include <stdint.h>\n\n")
        f.write("\n")
         
        first = True
        for file in cpu_cmake:
            if first==True:
                f.write("#if ")
                first = False
            else:
                f.write("#elif ")
            f.write(f"defined(__{file}__) || defined(__AT{file}__)\n")
            f.write(f"#    include <core++/{file.lower()}++.h>\n")
        f.write("#endif\n")
 
    # create core.h
    with open(f"src/core++/core.cpp", "w") as f:
        f.write("#include <core++/core.h>\n")
        f.write("\n")
         
        first = True
        for file in cpu_cmake:
            if first==True:
                f.write("#if ")
                first = False
            else:
                f.write("#elif ")
            name = file.replace("AT", "")
            f.write(f"defined(__{file}__) || defined(__AT{file}__)\n")
            f.write(f"#    include <core++/{file.lower()}++.cpp>\n")
        f.write("#endif\n")
 
    # create core.h
    with open(f"src/core/core.h", "w") as f:
        f.write("#pragma once\n")
        f.write("\n")
        first = True
        for file in cpu_cmake:
            if first==True:
                f.write("#if ")
                first = False
            else:
                f.write("#elif ")
            f.write(f"defined(__{file}__) || defined(__AT{file}__)\n")
            f.write(f"#    include <{file.lower()}.h>\n")
        f.write("#endif\n")

def pattern_to_regex(pattern):
    regex = "^"
    for c in pattern:
        if c.isspace() or c.isalnum():
            regex += c
        elif c=="-" or c==":":
            regex += f"\{c}"
        elif c=="*":
            regex += ".*"
        else:
            print(f"{pattern}: unhandled char {c}", file=sys.stderr)
            exit(1)
    return regex+"$"

def get_el_by_condition(tree, requires, after=None):
    req = dict(requires)
    res, validates, afterfound = _get_el_by_condition(tree, req, [], after, False)
    for v in validates:
        del req[v]
        
    if len(req)==0:
        return res
    return None

ntab = 0
# At the beginning of every .py file in the project
def tab(fn):
    from functools import wraps
    import inspect
    @wraps(fn)
    def wrapper(*args, **kwargs):
        global ntab
        ntab += 1 
        out = fn(*args, **kwargs)
        ntab -= 1
        # Return the return value
        return out
    return wrapper

def tabs():
    global ntab
    res = ""
    for i in range(ntab):
        res += "  "
    return res

# requires is dict of attribute/value 
@tab
def _get_el_by_condition(tree, requires, parentmatches, after, afterfound):
    if after is None:
        afterfound = True

    res = None
    resvalidates = []
    for el in tree.getchildren():
#         print(f"{tabs()}.", el.tag, el.attrib)

        # search for matching attributes
        elmatches = []
        for attr in el.attrib:
            for r in requires:
                pattern = re.compile(pattern_to_regex(requires[r]))
#                     print("==", pattern_to_regex(req[r]), req[r], pattern.match(el.attrib[attr]))
                if attr in requires and pattern.match(el.attrib[attr]) is not None and r not in elmatches:
                    elmatches.append(r)

        # match childs
        subel, childmatches, afterfound = _get_el_by_condition(el, requires, elmatches, after, afterfound)
        
        req = dict(requires)
        if afterfound==True:
            for v in parentmatches:
                if v in req:
                    del req[v]

            for v in elmatches:
                if v in req:
                    del req[v]
            
            for v in childmatches:
                if v in req:
                    del req[v]
        
        if el==after:
            afterfound = True

        if len(req)==0:
            # all was matched 
#             print(f"{tabs()}--", elmatches+childmatches)
            if subel is not None:
                return subel, elmatches+childmatches, afterfound
            else:
                return el, elmatches+childmatches, afterfound

    return res, resvalidates, afterfound

def get_condition(tree, id):
    requires = []

    conditions = tree.xpath("//conditions/condition")
    condition = None
    for c in conditions:
        if c.get("id")==id:
            condition = c
    
    if condition is None:
        return []

    for require in condition.xpath("require"):
        req = {}
        for attr in require.attrib:
            req[attr] = require.attrib[attr]
        requires.append(req)
        
    return requires

def get_devices(tree, condition_id):
    requires = get_condition(tree, condition_id)
    
    devices = []
    device = None
    for require in requires:
#         print("+++", require)
        el = get_el_by_condition(tree, require)
        while el is not None:
#             print("  -", el.tag, el.attrib)
            if el.tag=="device" and el.get("Dname") is not None:
#                 print("  +", el, el.get("Dname"))
                devices.append(el.get("Dname"))
            el = get_el_by_condition(tree, require, el)

    return devices
        
def to_gcc_name(name):
    name = name.lower()
    
    if '+' in name:
        name = name.replace('+', "plus")
    return name

if __name__ == "__main__":
    main()
