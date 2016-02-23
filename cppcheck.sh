#!/usr/bin/env bash

cppcheck \
    --enable=all \
    --platform=unix64 \
    --language=c++ \
    --std=c++11 \
    --template=gcc \
    --suppress=missingIncludeSystem \
    ${PWD}/src

