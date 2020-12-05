import sys
import os
import re

def main():
    if len(sys.argv)!=2:
        print("usage: patch-ld-script-gcc.py path", file=sys.stderr)
        exit(1)

    rootdir = sys.argv[1]
    
    for root, subdirs, files in os.walk(rootdir):
        for file in files:
            if file.endswith(".ld") and "gcc" in root:
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
            newlines.append("BOOTLOADER_SIZE = DEFINED(BOOTLOADER_SIZE) ? BOOTLOADER_SIZE : 0x0000;\n") # does not work with clang
        
        if re.search("^ *rom *\(.*$", line):
            line = re.sub(r"(.*0x[0-9a-fA-F]+)(.*0x[0-9a-fA-F]+)(.*)", r"\1+BOOTLOADER_SIZE\2-BOOTLOADER_SIZE\3", line)

        newlines.append(line)

    with open(file, "w") as f:
        f.writelines(newlines)

if __name__ == "__main__":
    main()
