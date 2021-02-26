#pragma once

#include <spck/renderer/backend/opengl/opengl_shader.hpp>
#include <spck/renderer/backend/opengl/opengl_vertex_array.hpp>
#include <spck/renderer/backend/opengl/opengl_vertex_buffer.hpp>

namespace spck {

class opengl_backend {
public:
    using shader = opengl_shader;
    using vertex_array = opengl_vertex_array;
    using vertex_buffer = opengl_vertex_buffer;
};

}