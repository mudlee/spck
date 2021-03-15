#pragma once

#include <functional>
#include <memory>

#include <spck/api.hpp>
#include <spck/messaging/event.hpp>
#include <spck/renderer/graphics_context.hpp>
#include <spck/utils/noncopyable.hpp>

namespace spck {

using event_callback_fn = std::function<void(event &)>;

class SPCK_API window : noncopyable {
public:
    explicit window(const graphics_context& context);
    virtual ~window();

    void set_event_callback(const event_callback_fn &callback) { data.event_callback = callback; }
    void frame_end();

private:
    struct window_data {
        event_callback_fn event_callback;
    };

    GLFWwindow* handle;
    window_data data;
    const graphics_context& context;
};

}
