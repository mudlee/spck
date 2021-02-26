#pragma once

#include <spck/renderer/shader.hpp>

#include <glad/glad.h>

namespace spck {

class opengl_shader: public shader {
public:
    opengl_shader(const char* vertex_shader, const char* fragment_shader);

    opengl_shader(const opengl_shader &) = delete;

    opengl_shader &operator=(const opengl_shader &) = delete;

    void start() override;

    void stop() override;

    ~opengl_shader();

private:
    static GLuint construct_shader(const char* shader, GLuint type);

private:
    GLuint program_id;
};

}

