#pragma once

#include <spck/renderer/command.hpp>
#include <spck/renderer/backend/opengl/opengl_command.hpp>
#include <spck/renderer/backend/opengl/opengl_context.hpp>
#include <spck/renderer/backend/opengl/opengl_index_buffer.hpp>
#include <spck/renderer/backend/opengl/opengl_shader.hpp>
#include <spck/renderer/backend/opengl/opengl_vertex_array.hpp>
#include <spck/renderer/backend/opengl/opengl_vertex_buffer.hpp>

namespace spck {

class opengl_backend {
public:
    using context = opengl_context;
    using shader = opengl_shader;
    using vertex_array = opengl_vertex_array;
    using vertex_buffer = opengl_vertex_buffer;
    using index_buffer = opengl_index_buffer;
    using draw_indexed_command = opengl_draw_indexed_command;
};

}