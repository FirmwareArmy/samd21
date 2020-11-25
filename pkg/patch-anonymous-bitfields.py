import sys
import os
import re

def main():
    if len(sys.argv)!=2:
        print("usage: patch-anonymous-bitfields.py path", file=sys.stderr)
        exit(1)

    rootdir = sys.argv[1]
    
    for root, subdirs, files in os.walk(rootdir):
        for file in files:
            if file.endswith(".h"):
                print("patch:", os.path.join(root, file))
                patch_file(os.path.join(root, file))
                
def patch_file(file):
    with open(file, "r") as f:
        lines = f.readlines()
#         print(lines)
    
    newlines = []
    i = 0
    for line in lines:
        end = False
        while(end==False):
            newline = re.sub(" :([0-9])", f" _{i}:\\1", line, 1)
            if newline!=line:
                i += 1
            else:
                end = True
            line = newline
        newlines.append(line)
        
#     if i>0:
#         print(newlines)

    with open(file, "w") as f:
        f.writelines(newlines)

if __name__ == "__main__":
    main()
