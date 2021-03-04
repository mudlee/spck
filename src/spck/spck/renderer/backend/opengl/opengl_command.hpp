#pragma once

#include <glad/glad.h>

#include <spck/renderer/command.hpp>

namespace spck {

class opengl_command : public command {
public:
    static void draw_indexed(const vertex_array& vao) {
        glDrawElements(GL_TRIANGLES, vao.get_ebo_size(), GL_UNSIGNED_INT, nullptr);
    };
};

}