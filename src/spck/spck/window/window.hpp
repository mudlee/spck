#pragma once

#include <functional>
#include <string>
#include <utility>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <spck/api.hpp>
#include <spck/messaging/event.hpp>
#include <spck/renderer/graphics_context.h>

namespace spck {
using event_callback_fn = std::function<void(event &)>;

class SPCK_API window {
public:
    explicit window(std::shared_ptr<graphics_context> context);

    virtual ~window();

    void set_event_callback(const event_callback_fn &callback) { data.event_callback = callback; }

    void frame_end();

private:
    struct window_data {
        event_callback_fn event_callback;
    };

    GLFWwindow *handle{};
    window_data data;
    std::shared_ptr<graphics_context> context;
};
} // namespace spck
