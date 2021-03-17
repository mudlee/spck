#pragma once

#include <GLFW/glfw3.h>
#include <spck/utils/noncopyable.hpp>

namespace spck {

class graphics_context : noncopyable {
public:
    graphics_context() = default;
    virtual ~graphics_context() = default;

    virtual void init() const = 0;
    virtual void window_created(GLFWwindow* handle) = 0;
    virtual void clear(float r, float g, float b, float a) = 0;
    virtual void swap_buffers(float frameTime, GLFWwindow* handle) = 0;
    virtual void window_resized(int new_width, int new_height) = 0;
};

}