#include "window.hpp"
#include <spck/log.hpp>
#include <spck/messaging/application_event.hpp>
#include <spck/messaging/key_event.hpp>

namespace spck {
window::window() : handle(nullptr) {
    SPCK_LOG_DEBUG("Creating m_Window...");

    if (!glfwInit()) {
        SPCK_LOG_ERROR("Failed to initialize GLFW");
    }

    glfwSetErrorCallback([](int error, const char *description) {
        SPCK_LOG_ERROR("GLFW ERROR. Code: {}, message: {}", error, description);
        exit(EXIT_FAILURE);
    });

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    // TODO: OpenGL specific stuff. Will be moved to its place when we have a clear renderer structure
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    // TODO: OpenGL specific stuff. Will be moved to its place when we have a clear renderer structure

    handle = glfwCreateWindow(800, 600, "SPCK", nullptr, nullptr);
    if (handle == nullptr) {
        SPCK_LOG_ERROR("Failed to Create GLFW m_Window");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(handle);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        SPCK_LOG_ERROR("Failed to initialize GLAD");
        exit(EXIT_FAILURE);
    }

    SPCK_LOG_DEBUG("Window created");

    glfwSetWindowUserPointer(handle, &data);

    glfwSetKeyCallback(handle, [](GLFWwindow *w, int key, int scancode, int action, int mods) {
        window_data &data = *(window_data *)glfwGetWindowUserPointer(w);

        switch (action) {
        case GLFW_PRESS:
            key_pressed_event ev(key);
            data.event_callback(ev);
            break;
            // TODO: handle release, repeat
        }
    });

    glfwSetWindowCloseCallback(handle, [](GLFWwindow *w) {
        window_data &data = *(window_data *)glfwGetWindowUserPointer(w);
        window_closed_event ev;
        data.event_callback(ev);
    });
}

window::~window() {
    if (handle) {
        glfwDestroyWindow(handle);
        glfwTerminate();
    }
}

void window::frame_end() {
    glfwPollEvents();
    glfwSwapBuffers(handle);
}

} // namespace spck
