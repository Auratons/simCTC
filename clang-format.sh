#!/usr/bin/env bash

# OPTIONALLY -style=Webkit"
clang-format -i \
    -style='{UseTab: Never, IndentWidth: 4, PointerBindsToType: true, PointerAlignment: Right}' \
    ${PWD}/src/*.{h,ipp,cc} ${PWD}/src/gui/*.{h,ipp,cc} 

