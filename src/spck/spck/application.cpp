#include <spck/application.hpp>
#include <spck/renderer/renderer.hpp>
#include <spck/window/window.hpp>
#include <memory>

namespace spck {

application::application()
    : context(),
      win(context),
      command_queue(){
    SPCK_LOG_DEBUG("Creating application");
    // TODO: use properties to setup global variables like render backend
    win.set_event_callback([this](auto &&PH1) { on_event(std::forward<decltype(PH1)>(PH1)); });
}

void application::run() {
    SPCK_LOG_DEBUG("Running application");

    while (running) {
        on_begin_frame();
        context.clear(1.0f, 1.0f, 1.0f, 1.0f);

        on_update();
        command_queue.flush();

        on_end_frame();
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