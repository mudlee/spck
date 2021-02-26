#include <spck/application.hpp>
#include <spck/messaging/application_event.hpp>
#include <spck/messaging/event.hpp>
#include <spck/messaging/key_event.hpp>
#include <spck/window/window.hpp>

namespace spck {

void application::run() {
    window win;
    win.set_event_callback([this](auto &&PH1) { on_event(std::forward<decltype(PH1)>(PH1)); });

    while (running) {
        win.frame_end();
    }
}

void application::on_event(event &ev) {
    SPCK_LOG_DEBUG("Event arrived: {0}", ev.get_name());
    // For now, we can either close it with ESC or the window's close button.
    event_dispatcher dispatcher(ev);
    dispatcher.dispatch<window_closed_event>(BIND_EVENT_FN(application::on_window_closed));
    dispatcher.dispatch<key_pressed_event>(BIND_EVENT_FN(application::on_key_pressed));
}

bool application::on_window_closed(window_closed_event &e) { return shutdown(); }

bool application::on_key_pressed(key_pressed_event &e) {
    if (e.get_key_code() == GLFW_KEY_ESCAPE) {
        return shutdown();
    }
    return false;
}

bool application::shutdown() {
    SPCK_LOG_INFO("Shutting down the engine...");
    running = false;
    return true;
}

} // namespace spck