#pragma once

#include <glad/glad.h>

namespace spck {

class graphics_context {
public:
    graphics_context() = default;
    ~graphics_context() = default;
    graphics_context(const graphics_context &) = delete;
    graphics_context &operator=(const graphics_context &) = delete;

    virtual void init() = 0;
    virtual void window_created() = 0;
    virtual void clear(float r, float g, float b, float a) = 0;
    virtual void swap_buffers(float frameTime) = 0;
    virtual void window_resized(int new_width, int new_height) = 0;
};

}