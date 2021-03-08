#pragma once

#include <memory>
#include <spck/utils.hpp>
#include <spck/renderer/vertex_buffer_layout.hpp>

namespace spck {

class vertex_buffer {
public:
    vertex_buffer(
        const float *vertices,
        uint32_t size,
        std::shared_ptr<vertex_buffer_layout> layout
    ): layout(std::move(layout)) {}
    ~vertex_buffer() = default;
    DELETE_COPY_METHODS(vertex_buffer)

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

public:
    uint32_t id{};
    std::shared_ptr<vertex_buffer_layout> layout;
};

}