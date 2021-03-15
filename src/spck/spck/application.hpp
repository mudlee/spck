#pragma once

#include <spck/api.hpp>
#include <spck/log.hpp>
#include <spck/messaging/application_event.hpp>
#include <spck/messaging/event.hpp>
#include <spck/messaging/key_event.hpp>
#include <spck/renderer/renderer.hpp>
#include <spck/renderer/command/standard_command_queue.hpp>
#include <spck/utils/noncopyable.hpp>
#include <spck/window/window.hpp>

namespace spck {

class SPCK_API application : noncopyable {
public:
    application();
    virtual ~application() = default;

    void run();
    virtual void on_begin_frame() = 0;
    virtual void on_update() = 0;
    virtual void on_end_frame() = 0;

protected:
    standard_command_queue command_queue;

private:
    void on_event(event &event);
    bool on_window_closed(window_closed_event &e);
    bool on_key_pressed(key_pressed_event &e);
    bool shutdown();

private:
    bool running = true;
    renderer::context context;
    window win;
};

}
