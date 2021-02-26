#pragma once

#include <glad/glad.h>

namespace spck {

struct vertex_layout_attribute {
    GLint data_size;
    GLenum data_type;
    GLboolean normalized;
    GLsizei stride;
    const void* offset;
};

struct vertex_buffer_layout {
    std::vector<vertex_layout_attribute> attributes;
};

}