#include "window.hpp"
#include <spck/log.hpp>
#include <spck/messaging/application_event.hpp>
#include <spck/messaging/key_event.hpp>
#include <spck/renderer/renderer.hpp>

namespace spck {
window::window(std::shared_ptr<graphics_context> context) : handle(nullptr), context(context) {
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

    context->init();

    handle = glfwCreateWindow(800, 600, "SPCK", nullptr, nullptr);
    if (handle == nullptr) {
        SPCK_LOG_ERROR("Failed to Create GLFW m_Window");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // TODO: context->window_created();

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
