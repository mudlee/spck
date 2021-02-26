#pragma once

#include <spck/api.hpp>
#include <spck/log.hpp>
#include <spck/messaging/application_event.hpp>
#include <spck/messaging/event.hpp>
#include <spck/messaging/key_event.hpp>
#include <spck/renderer/renderer.hpp>

namespace spck {

class SPCK_API application {
public:
    application() = default;

    virtual ~application() = default;

    void run();

private:
    void on_event(event &event);
    bool on_window_closed(window_closed_event &e);
    bool on_key_pressed(key_pressed_event &e);
    bool shutdown();

private:
    bool running = true;
};

}
