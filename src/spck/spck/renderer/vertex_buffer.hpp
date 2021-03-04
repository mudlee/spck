#pragma once

#include <spck/renderer/vertex_buffer_layout.hpp>

namespace spck {

class vertex_buffer {
public:
    vertex_buffer() = default;
    ~vertex_buffer() = default;
    vertex_buffer(const vertex_buffer &) = delete;
    vertex_buffer &operator=(const vertex_buffer &) = delete;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

public:
    GLuint id{};
    vertex_buffer_layout layout;
};

}