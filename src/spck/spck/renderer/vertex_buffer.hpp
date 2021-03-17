#pragma once

#include <memory>
#include <span>
#include <spck/renderer/vertex_buffer_layout.hpp>
#include <spck/utils/noncopyable.hpp>

namespace spck {

class vertex_buffer : noncopyable {
public:
    vertex_buffer(
        std::span<float> vertices,
        uint32_t size,
        std::shared_ptr<vertex_buffer_layout> layout
    ): layout(std::move(layout)) {}
    virtual ~vertex_buffer() = default;

    virtual void bind() = 0;
    virtual void unbind() = 0;

public:
    uint32_t id{};
    std::shared_ptr<vertex_buffer_layout> layout;
};

}