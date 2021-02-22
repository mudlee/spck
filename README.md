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

### Develop with CLion

To use CLion, first run the install script, then you can open CLion.

### Install

```bash
# On Linux / OSX
$ ./install.sh
```

### Build

```bash
# On Linux / OSX
$ ./build.sh
```

### Run

```bash
# On Linux / OSX
$ ./run.sh
```

### Nearest TODOs

- Static analyzer
- CI
- Simple glfw window
- OpenGL triangle
- SPIR-V shaders from glsl source
- Resizable window
- OpenGL cube
- Ortho & Perspective camera
- ECS
- Instanced rendering
