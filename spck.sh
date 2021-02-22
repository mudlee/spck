#!/bin/sh

while test $# -gt 0; do
  case "$1" in
  -clean)
    shift
    rm -rf ./Build
    ;;
  -install)
    shift
    mkdir -p Build && cd Build
    conan install .. --build=fmt --build=spdlog&& cmake .. -G Ninja
    ninja
    # CLion Support
    cd ..
    mkdir -p cmake-build-debug
    cd cmake-build-debug
    conan install .. --build=fmt --build=spdlog
    ;;
  -build)
    shift
    cd Build
    ninja
    cd ..
    ;;
  -run)
    shift
    ./Build/bin/Sandbox
    ;;
  *)
    echo "$1 is an invalid flag. Use [-install|-clean|-build|-run]"
    return 1;
  ;;
  esac
done