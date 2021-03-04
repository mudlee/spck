#pragma once

#include <glad/glad.h>

#include <spck/log.hpp>
#include <spck/renderer/index_buffer.hpp>

namespace spck {

class opengl_index_buffer : public index_buffer {
public:
    opengl_index_buffer(const int* indices, uint32_t size2) {
        size = size2; // TODO
        glGenBuffers(1, &id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
        SPCK_LOG_DEBUG("OpenGL EBO created: {0}", id);
    }

    ~opengl_index_buffer() {
        glDeleteBuffers(1, &id);
    };

    void bind() const override {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    };

    void unbind() const override {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    };
};

}
