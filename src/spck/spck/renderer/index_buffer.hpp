#pragma once

#include <spck/renderer/vertex_buffer_layout.hpp>
#include <spck/utils/noncopyable.hpp>

namespace spck {

class index_buffer : noncopyable {
public:
    index_buffer(const int* indices, uint32_t size): size(size){};
    virtual ~index_buffer() = default;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

public:
    uint32_t id{};
    uint32_t size;
};

}