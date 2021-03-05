#pragma once

#include <spck/utils.hpp>
#include <spck/renderer/vertex_buffer.hpp>
#include <spck/renderer/index_buffer.hpp>

namespace spck {

class vertex_array {
public:
    vertex_array() = default;
    virtual ~vertex_array() = default;
    DELETE_COPY_METHODS(vertex_array)

    virtual void bind() const = 0;
    virtual void unbind() const = 0;
    virtual void add_vbo(const vertex_buffer& buffer) const = 0;
    virtual void set_ebo(const index_buffer& buffer) = 0;

     [[nodiscard]] uint32_t get_ebo_size() const { return ebo_size; };

protected:
    uint32_t id{};
    uint32_t ebo_size{};
};

}