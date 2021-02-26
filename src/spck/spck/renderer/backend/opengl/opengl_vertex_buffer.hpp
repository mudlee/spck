#pragma once

#include <spck/log.hpp>
#include <spck/renderer/vertex_buffer_layout.hpp>
#include <spck/renderer/vertex_buffer.hpp>

#include <glad/glad.h>

namespace spck {

class opengl_vertex_buffer : public vertex_buffer {
public:
    opengl_vertex_buffer(
        const float* vertices,
        uint32_t size,
        vertex_buffer_layout& layout2
    ) {
        layout = layout2; // TODO: pleeeease solve it somehow :)
        glGenBuffers(1, &id);
        glBindBuffer(GL_ARRAY_BUFFER, id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        SPCK_LOG_DEBUG("OpenGL VBO created: {0}", id);
    }

    ~opengl_vertex_buffer() {
        glDeleteBuffers(1, &id);
    };

    void bind() override {
        glBindBuffer(GL_ARRAY_BUFFER, id);
    };

    void unbind() override {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    };
};

}
