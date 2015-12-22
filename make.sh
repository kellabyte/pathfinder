#!/bin/bash
./compile_dependencies.sh

unamestr=`uname`

if [[ "$unamestr" == 'Linux' ]]; then
    ./compile_make.sh
elif [[ "$unamestr" == 'Darwin' ]]; then
    ./compile_xcode.sh
elif [[ "$unamestr" =~ 'CYGWIN' ]]; then
    ./compile_make.sh
fi
