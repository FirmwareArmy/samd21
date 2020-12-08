import sys
import os
import re
import pathlib
import shutil

def main():
    if len(sys.argv)!=2:
        print("usage: patch-ld-script-clang.py path", file=sys.stderr)
        exit(1)

    rootdir = sys.argv[1]
    
    for root, subdirs, files in os.walk(rootdir):
        for subdir in subdirs:
            if subdir=="gcc" and "gcc" not in root:
                clangpath = os.path.join(root, "clang")
                if os.path.exists(clangpath)==False:
                    print("copy", os.path.join(root, subdir), "->", clangpath)
                    shutil.copytree(os.path.join(root, subdir), clangpath)
                    shutil.move(os.path.join(root, "clang", "gcc"), os.path.join(root, "clang", "clang"))
                
    for root, subdirs, files in os.walk(rootdir):
        for file in files:
            if file.endswith(".ld") and "clang" in root:
                print("patch:", os.path.join(root, file))
                patch_file(os.path.join(root, file))
                
def patch_file(file):
    with open(file, "r") as f:
        lines = f.readlines()
#         print(lines)

    newlines = []
    i = 0
    for line in lines:
        if line.startswith("BOOTLOADER_SIZE"):
            # already patched
            return

        if line=="MEMORY\n":
            newlines.append("PROVIDE( BOOTLOADER_SIZE = 0x0000 ) ;\n")
        
        if line.startswith("STACK_SIZE ="):
            line = "PROVIDE( STACK_SIZE = 0x2000 ) ;\n"

        if re.search("^ *rom *\(.*$", line):
            line = re.sub(r"(.*0x[0-9a-fA-F]+)(.*0x[0-9a-fA-F]+)(.*)", r"\1+BOOTLOADER_SIZE\2-BOOTLOADER_SIZE\3", line)

        if ".ARM.exidx is sorted" in line:
            newlines.append("    .metadata : ALIGN(64)\n")
            newlines.append("    {\n")
            newlines.append("        KEEP(*(.metadata))\n")
            newlines.append("    } > rom\n")
            newlines.append("\n")

        newlines.append(line)

    with open(file, "w") as f:
        f.writelines(newlines)

if __name__ == "__main__":
    main()
