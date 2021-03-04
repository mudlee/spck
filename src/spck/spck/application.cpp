#include <spck/application.hpp>
#include <spck/renderer/renderer.hpp>
#include <spck/window/window.hpp>

namespace spck {

void application::run() {
    // TODO: use properties to setup global variables like render backend
    const auto context = std::make_shared<renderer::context>();

    window win(context);
    win.set_event_callback([this](auto &&PH1) { on_event(std::forward<decltype(PH1)>(PH1)); });

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
    const float vertices[] = {
        -0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
    };

    const int indices[] = {
        0, 1, 3, 3, 1, 2,
    };

    // TODO: move this logic out when the architecture is ready
    auto shader = renderer::shader(vertex_source, fragment_source);
    auto attrib = vertex_layout_attribute{
        3,
        shader::data_type::FLOAT,
        false,
        3 * sizeof(float),
        nullptr
    };

    auto attribs = std::vector<vertex_layout_attribute>{attrib};
    auto layout = vertex_buffer_layout{attribs};

    auto vao = renderer::vertex_array();
    auto vbo = renderer::vertex_buffer(vertices, sizeof(vertices), layout);
    auto ebo = renderer::index_buffer(indices, sizeof(indices));

    vao.add_vbo(vbo);
    vao.set_ebo(ebo);

    while (running) {
        context->clear(1.0f, 1.0f, 1.0f, 1.0f);
        shader.start();
        vao.bind();

        // TODO: move this whole rendering logic to a commandqueue/renderer
        renderer::command::draw_indexed(vao);

        win.frame_end();
        vao.unbind();
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