#pragma once

#include <span>

#include <spck/log.hpp>
#include <spck/renderer/backend/opengl/vendor.hpp>
#include <spck/renderer/index_buffer.hpp>

namespace spck {

class opengl_index_buffer : public index_buffer {
public:
    opengl_index_buffer(const std::span<int> indices, uint32_t size): index_buffer(indices, size) {
        glGenBuffers(1, &id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices.data(), GL_STATIC_DRAW);
        SPCK_LOG_DEBUG("OpenGL EBO created: {0}", id);
    }

    ~opengl_index_buffer() override {
        glDeleteBuffers(1, &id);
    };

    void bind() override {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    };

    void unbind() override {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    };
};

}
