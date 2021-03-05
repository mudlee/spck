#pragma once

#include <GLFW/glfw3.h>
#include <spck/utils.hpp>

namespace spck {

class graphics_context {
public:
    graphics_context() = default;
    ~graphics_context() = default;
    DELETE_COPY_METHODS(graphics_context)

    virtual void init() const = 0;
    virtual void window_created(GLFWwindow* handle) const = 0;
    virtual void clear(float r, float g, float b, float a) const = 0;
    virtual void swap_buffers(float frameTime, GLFWwindow* handle) const = 0;
    virtual void window_resized(int new_width, int new_height) const = 0;
};

}