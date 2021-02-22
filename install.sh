#!/bin/sh

mkdir Build && cd Build
conan install ..&& cmake .. -G Ninja
ninja