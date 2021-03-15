#pragma once

#include <spck/renderer/command/command.hpp>
#include <spck/renderer/vertex_array.hpp>

namespace spck {

class draw_indexed_command : public command {
public:
    explicit draw_indexed_command(std::shared_ptr<vertex_array> vao): vao(std::move(vao)) {}

    void render() override = 0;

protected:
    std::shared_ptr<vertex_array> vao;
};

}