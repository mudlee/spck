#pragma once

#include <spck/renderer/vertex_array.hpp>

namespace spck {

class command {
public:
    command() = default;
    ~command() = default;
    command(const command &) = delete;
    command &operator=(const command &) = delete;

    static void draw_indexed(const vertex_array& vao);
};

}