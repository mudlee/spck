#pragma once

#include <spck/utils.hpp>
#include <spck/renderer/vertex_buffer_layout.hpp>

namespace spck {

class index_buffer {
public:
    index_buffer(const int* indices, uint32_t size): size(size){};
    ~index_buffer() = default;
    DELETE_COPY_METHODS(index_buffer)

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

public:
    uint32_t id{};
    uint32_t size{};
};

}