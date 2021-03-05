#pragma once

#include <spck/renderer/backend/opengl/vendor.hpp>
#include <spck/renderer/command.hpp>

namespace spck {

class opengl_draw_indexed_command : public draw_indexed_command {
public:
    explicit opengl_draw_indexed_command(const std::shared_ptr<vertex_array> &vao) : draw_indexed_command(vao) {
    }

    void render() override {
        vao->bind();
        glDrawElements(GL_TRIANGLES, vao->get_ebo_size(), GL_UNSIGNED_INT, nullptr);
        vao->unbind();
    }
};

}