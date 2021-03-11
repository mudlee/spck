# Spck Engine

This project is intended to be a C++ OpenGL (and maybe later Vulkan) rendering engine,
that servers my C++ and computer graphics learning.

Supported platforms:
 - Windows
 - Linux
 - OSX

## Requirements

- [CMake](https://cmake.org/)
- [Conan](https://conan.io/)
- [Ninja](https://ninja-build.org/)

## Usage

### Get the Code

```bash
$ git clone git@github.com:mudlee/spck.git
```

### Notes

#### Develop with CLion

To use CLion, after starting it up run the conan to install dependencies:
```bash
$ mkdir -p cmake-build-debug && cd cmake-build-debug && conan install .. --build=fmt --build=spdlog --build=glad --build=glfw
```

Then go in CLion go to `Tools -> CMake -> Reload CMake Project` and you're good to go.

#### Develop on M1 ARM Mac

Replace `arm64` to `armv8` in `~/.conan/profiles/default`

### Install

```bash
$ mkdir -p build && cd build && conan install .. --build=fmt --build=spdlog --build=glad --build=glfw
```

### Build

```bash
$ cd build && cmake .. -G Ninja && ninja
```

### Run

```bash
$ ./build/bin/sandbox
```

### QA

```bash
$ cd build && ctest
```