#pragma once

#include <span>

#include <spck/log.hpp>
#include <spck/renderer/backend/opengl/vendor.hpp>
#include <spck/renderer/vertex_buffer_layout.hpp>
#include <spck/renderer/vertex_buffer.hpp>

namespace spck {

class opengl_vertex_buffer : public vertex_buffer {
public:
    opengl_vertex_buffer(
        std::span<float> vertices,
        uint32_t size,
        const std::shared_ptr<vertex_buffer_layout> &layout
    ): vertex_buffer(vertices, size, layout) {
        glGenBuffers(1, &id);
        glBindBuffer(GL_ARRAY_BUFFER, id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices.data(), GL_STATIC_DRAW);
        SPCK_LOG_DEBUG("OpenGL VBO created: {0}", id);
    }

    ~opengl_vertex_buffer() override {
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
