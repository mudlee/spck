#pragma once

#include <glad/glad.h>
#include <spck/renderer/graphics_context.h>

namespace spck {

class opengl_context : public graphics_context {
public:
    void init() override {
        SPCK_LOG_DEBUG("Initializing OpenGL context...");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    }

    void window_created(GLFWwindow* handle) override {
        glfwMakeContextCurrent(handle);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            SPCK_LOG_ERROR("Failed to initialize GLAD");
            exit(EXIT_FAILURE);
        }
    }

    void clear(float r, float g, float b, float a) override {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT); // TODO has to be provided
    }

    void swap_buffers(float frameTime, GLFWwindow* handle) override {
        // TODO: calculate parameters from a command queue
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(handle);
    }

    void window_resized(int new_width, int new_height) override {
        // TODO
    }
};

}