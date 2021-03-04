#include <spck/window/window.hpp>
#include <spck/log.hpp>
#include <spck/messaging/application_event.hpp>
#include <spck/messaging/key_event.hpp>

namespace spck {
window::window(const std::shared_ptr<graphics_context>& context) : handle(nullptr), context(context) {
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

    context->window_created(handle);
    SPCK_LOG_DEBUG("Window created");

    glfwSetWindowUserPointer(handle, &data);

    glfwSetKeyCallback(handle, [](GLFWwindow *w, int key, int scancode, int action, int mods) {
        auto &data_ref = *(window_data *)glfwGetWindowUserPointer(w);

        switch (action) {
        case GLFW_PRESS:
            key_pressed_event ev(key);
            data_ref.event_callback(ev);
            break;
            // TODO: handle release, repeat
        }
    });

    glfwSetWindowCloseCallback(handle, [](GLFWwindow *w) {
        auto &data_ref = *(window_data *)glfwGetWindowUserPointer(w);
        window_closed_event ev;
        data_ref.event_callback(ev);
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
    // TODO: calculate frame time
    context->swap_buffers(1.0f, handle);
}

} // namespace spck
