#include <spck/application.hpp>
#include <spck/renderer/renderer.hpp>
#include <spck/window/window.hpp>

namespace spck {

application::application() {
    SPCK_LOG_DEBUG("Creating application");
    // TODO: use properties to setup global variables like render backend
    context = std::make_shared<renderer::context>();
    win = std::make_unique<window>(context);
    win->set_event_callback([this](auto &&PH1) { on_event(std::forward<decltype(PH1)>(PH1)); });
}

void application::run() {
    SPCK_LOG_DEBUG("Running application");
    // TODO: move this to sandbox, when the architecture is ready
    const char* vertex_source = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";
    const char* fragment_source = "#version 330 core\n"
                                  "out vec4 FragColor;\n"
                                  "\n"
                                  "void main()\n"
                                  "{\n"
                                  "    FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
                                  "}\0";

    auto shader = renderer::shader(vertex_source, fragment_source);

    while (running) {
        context->clear(1.0f, 1.0f, 1.0f, 1.0f);
        shader.start();

        renderer::command_queue::flush();

        win->frame_end();
        shader.stop();
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