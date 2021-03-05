#pragma once

#include <spck/log.hpp>
#include <spck/renderer/vertex_array.hpp>
#include <spck/renderer/backend/opengl/type_converter.hpp>
#include <spck/renderer/backend/opengl/vendor.hpp>

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

    void bind() const override {
        glBindVertexArray(id);
        glEnableVertexAttribArray(0);
    }

    void unbind() const override {
        glBindVertexArray(0);
    }

    void add_vbo(const vertex_buffer &buffer) const override {
        bind();
        buffer.bind();

        for(int i=0;i<buffer.layout->attributes.size();i++){
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(
                i,
                buffer.layout->attributes.at(i).data_size,
                type_converter::shader_data_type_to_gl_enum(buffer.layout->attributes.at(i).data_type),
                buffer.layout->attributes.at(i).normalized,
                buffer.layout->attributes.at(i).stride,
                buffer.layout->attributes.at(i).offset
            );
        }

        unbind();
        buffer.unbind();
        SPCK_LOG_DEBUG("OpenGL VBO [{0}] added to VAO [{1}]", buffer.id, id);
    }

    void set_ebo(const index_buffer &buffer) override {
        ebo_size = buffer.size;
        bind();
        buffer.bind();
        unbind();
        buffer.unbind();
        SPCK_LOG_DEBUG("OpenGL EBO [{0}] added to VAO [{1}]", buffer.id, id);
    }
};

}