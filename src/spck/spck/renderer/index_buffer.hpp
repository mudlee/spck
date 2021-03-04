#pragma once

#include <spck/renderer/vertex_buffer_layout.hpp>

namespace spck {

class index_buffer {
public:
    index_buffer() = default;
    ~index_buffer() = default;
    index_buffer(const index_buffer &) = delete;
    index_buffer &operator=(const index_buffer &) = delete;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

public:
    GLuint id{};
    uint32_t size{};
};

}