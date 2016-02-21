#!/usr/bin/env bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 report-xmlfile"
    # debug spusteni
    cppcheck -j3 --enable=all --platform=unix64 --std=c++11 ${PWD}/src >/dev/null
else
    # spusteni s generovanim XML reportu
    cppcheck -j3 --enable=all --platform=unix64 --std=c++11 --xml ${PWD}/src 2>$1
fi

