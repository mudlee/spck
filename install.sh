#!/bin/sh

mkdir -p Build && cd Build
conan install ..&& cmake .. -G Ninja
ninja

# CLion Support
cd ..
mkdir -p cmake-build-debug
cd cmake-build-debug
conan install ..