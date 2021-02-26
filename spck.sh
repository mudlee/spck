#!/bin/sh

while test $# -gt 0; do
  case "$1" in
  -clean)
    shift
    rm -rf ./build
    ;;
  -install)
    shift
    mkdir -p build && cd build
    conan install .. --build=fmt --build=spdlog --build=glad --build=glfw && cmake .. -G Ninja
    ninja
    # CLion Support
    cd ..
    mkdir -p cmake-build-debug
    cd cmake-build-debug
    conan install .. --build=fmt --build=spdlog --build=glad --build=glfw 
    ;;
  -build)
    shift
    cd build
    ninja
    cd ..
    ;;
  -run)
    shift
    ./build/bin/sandbox
    ;;
  -test)
    shift
    cd build
    ctest
    cd ..
    ;;
  *)
    echo "$1 is an invalid flag. Use [-install|-clean|-build|-run]"
    return 1;
  ;;
  esac
done