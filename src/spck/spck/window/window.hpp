#pragma once

#include <functional>

#include <spck/api.hpp>
#include <spck/messaging/event.hpp>
#include <spck/renderer/graphics_context.hpp>

namespace spck {
using event_callback_fn = std::function<void(event &)>;

class SPCK_API window {
public:
    explicit window(const std::shared_ptr<graphics_context>& context);
    virtual ~window();
    window(const window &) = delete;
    window &operator=(const window &) = delete;

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
