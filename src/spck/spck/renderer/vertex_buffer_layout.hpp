#pragma once

#include <vector>
#include <spck/renderer/shader.hpp>

namespace spck {

struct vertex_layout_attribute {
    uint32_t data_size;
    shader::data_type data_type;
    bool normalized;
    int32_t stride;
    const void* offset;
};

struct vertex_buffer_layout {
    std::vector<vertex_layout_attribute> attributes;

    explicit vertex_buffer_layout(std::vector<vertex_layout_attribute>&& attributes) : attributes(std::move(attributes)) {}
};

}