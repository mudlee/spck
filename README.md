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

To use CLion, first run the install script, then you can open CLion.

#### Develop on M1 ARM Mac

Replace `arm64` to `armv8` in `~/.conan/profiles/default`

### Install

```bash
# On Linux / OSX
$ ./spck.sh -install
```

### Clean

```bash
# On Linux / OSX
$ ./spck.sh -clean
```

### Build

```bash
# On Linux / OSX
$ ./spck.sh -build
```

### Run

```bash
# On Linux / OSX
$ ./spck.sh -run
```

### QA

```bash
# Run tests
$ ./spck.sh -test
```