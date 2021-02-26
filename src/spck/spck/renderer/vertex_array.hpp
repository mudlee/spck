#pragma once

#import <spck/renderer/vertex_buffer.hpp>
#import <glad/glad.h>

namespace spck {

class vertex_array {
public:
    vertex_array() = default;
    virtual ~vertex_array() = default;
    vertex_array(const vertex_array &) = delete;
    vertex_array &operator=(const vertex_array &) = delete;

    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void add_vbo(vertex_buffer& buffer) = 0;

public:
    GLuint id{};

};

}