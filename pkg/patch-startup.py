import sys
import os
import re

def main():
    if len(sys.argv)!=2:
        print("usage: patch-bootloader.py path", file=sys.stderr)
        exit(1)

    rootdir = sys.argv[1]
    
    for root, subdirs, files in os.walk(rootdir):
        for file in files:
            if file=="startup_samd21.c":
                print("patch:", os.path.join(root, file))
                patch_file(os.path.join(root, file))
                
def patch_file(file):
    with open(file, "r") as f:
        lines = f.readlines()
#         print(lines)

    newlines = []
    i = 0
    for line in lines:
        if "__attribute__ ((used))" in line:
            # already patched
            return

        if "exception_table" in line:
            newlines.append("__attribute__ ((used))\n")

        newlines.append(line)

    if "clang" in file:
        newlines.append("\n")
        newlines.append("void _init()\n")
        newlines.append("{\n")
        newlines.append("}\n")

    with open(file, "w") as f:
        f.writelines(newlines)

if __name__ == "__main__":
    main()
