#!/bin/bash

xpl_path=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

cd ${xpl_path}

src_path=../../src

res=$(mktemp)
g++ -Wno-format -Wno-write-strings main.cpp -I${src_path} -o $res

# execute test
chmod +x $res
$res
rm $res