#pragma once

#include <spck/renderer/shader.hpp>
#include <spck/log.hpp>

#include <glad/glad.h>

namespace spck {

class opengl_shader: public shader {
public:
    opengl_shader(const char* vertex_shader, const char* fragment_shader) {
        SPCK_LOG_DEBUG("Creating shader program...");
        program_id = glCreateProgram();
        SPCK_LOG_DEBUG("Shader program created [{0}]", program_id);

        SPCK_LOG_DEBUG("Creating vertex shader...");
        auto vertex_id = construct_shader(vertex_shader, GL_VERTEX_SHADER);

        SPCK_LOG_DEBUG("Creating fragment shader...");
        auto fragment_id = construct_shader(fragment_shader, GL_FRAGMENT_SHADER);

        SPCK_LOG_DEBUG("Attaching shaders...");
        glAttachShader(program_id, vertex_id);
        glAttachShader(program_id, fragment_id);

        SPCK_LOG_DEBUG("Linking shader program [{0}]...", program_id);
        glLinkProgram(program_id);

        int program_linked;
        char program_info[1024];
        glGetProgramiv(program_id, GL_LINK_STATUS, &program_linked);
        if(!program_linked) {
            glGetProgramInfoLog(program_id, 1024, nullptr, program_info);
            SPCK_LOG_ERROR("Could not link shader program. Error: {0}", program_info);
            exit(EXIT_FAILURE);
        }

        SPCK_LOG_DEBUG("Shader program [{0}] linked, detaching shaders...", program_id);
        glDeleteShader(vertex_id);
        glDeleteShader(fragment_id);
    }

    ~opengl_shader() {
        glDeleteProgram(program_id);
    }

    opengl_shader(const opengl_shader &) = delete;

    opengl_shader &operator=(const opengl_shader &) = delete;

    void start() const override {
        glUseProgram(program_id);
    }

    void stop() const override {
        glUseProgram(0);
    }

private:
    static GLuint construct_shader(const char* shader, GLuint type) {
        auto id = glCreateShader(type);
        glShaderSource(id, 1, &shader, nullptr);
        glCompileShader(id);

        int success;
        char info[1024];
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(id, 1024, nullptr, info);
            SPCK_LOG_ERROR("Could not compile shader, error: {0}", info);
            exit(EXIT_FAILURE);
        }

        SPCK_LOG_DEBUG("Shader created: [{0}]", id);

        return id;
    }

private:
    GLuint program_id;
};

}

