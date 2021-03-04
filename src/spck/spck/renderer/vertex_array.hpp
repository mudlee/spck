#pragma once

#import <spck/renderer/vertex_buffer.hpp>
#import <spck/renderer/index_buffer.hpp>

namespace spck {

class vertex_array {
public:
    vertex_array() = default;
    virtual ~vertex_array() = default;
    vertex_array(const vertex_array &) = delete;
    vertex_array &operator=(const vertex_array &) = delete;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;
    virtual void add_vbo(vertex_buffer& buffer) const = 0;
    virtual void set_ebo(index_buffer& buffer) = 0;

    [[nodiscard]] uint32_t get_ebo_size() const { return ebo_size; };

protected:
    GLuint id{};
    uint32_t ebo_size{};
};

}