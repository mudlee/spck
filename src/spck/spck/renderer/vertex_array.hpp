#pragma once

#include <spck/renderer/index_buffer.hpp>
#include <spck/renderer/vertex_buffer.hpp>
#include <spck/utils/noncopyable.hpp>

namespace spck {

class vertex_array : noncopyable {
public:
    vertex_array() = default;
    virtual ~vertex_array() = default;

    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void add_vbo(vertex_buffer& buffer) = 0;
    virtual void set_ebo(index_buffer& buffer) = 0;

     [[nodiscard]] inline uint32_t get_ebo_size() const { return ebo_size; };

protected:
    uint32_t id{};
    uint32_t ebo_size{};
};

}