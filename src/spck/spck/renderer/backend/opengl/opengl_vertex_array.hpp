#pragma once

#include <spck/log.hpp>
#include <spck/renderer/vertex_array.hpp>

namespace spck {

class opengl_vertex_array : public vertex_array {
public:
    opengl_vertex_array() {
        glGenVertexArrays(1, &id);
        SPCK_LOG_DEBUG("OpenGL VAO created: {0}", id);
    }

    ~opengl_vertex_array() override {
        glDeleteVertexArrays(1, &id);
    };

    void bind() override {
        glBindVertexArray(id);
    }

    void unbind() override {
        glBindVertexArray(0);
    }

    void add_vbo(vertex_buffer &buffer) override {
        bind();
        buffer.bind();

        for(int i=0;i<buffer.layout.attributes.size();i++){
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(
                i,
                buffer.layout.attributes.at(i).data_size,
                buffer.layout.attributes.at(i).data_type,
                buffer.layout.attributes.at(i).normalized,
                buffer.layout.attributes.at(i).stride,
                buffer.layout.attributes.at(i).offset
            );
        }

        SPCK_LOG_DEBUG("OpenGL VBO [{0}] added to VAO [{1}]", buffer.id, id);
    }
};

}