#pragma once

#include <spck/spck.hpp>

class sandbox : public spck::application {
public:
    sandbox() {
        SPCK_LOG_DEBUG("Starting up sandbox");

        const float vertices[] = {
            -0.5f,  0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f,  0.5f, 0.0f,
        };

        const int indices[] = {
            0, 1, 3, 3, 1, 2,
        };

        auto attrib = spck::vertex_layout_attribute{
            3,
            spck::shader::data_type::FLOAT,
            false,
            3 * sizeof(float),
            nullptr
        };

        auto attribs = std::vector<spck::vertex_layout_attribute>{attrib};
        const auto layout = std::make_shared<spck::vertex_buffer_layout>(std::move(attribs));
        auto vao = std::make_shared<spck::renderer::vertex_array>();
        auto vbo = spck::renderer::vertex_buffer(vertices, sizeof(vertices), layout);
        auto ebo = spck::renderer::index_buffer(indices, sizeof(indices));

        vao->add_vbo(vbo);
        vao->set_ebo(ebo);

        auto command = std::make_shared<spck::renderer::draw_indexed_command>(vao);
        spck::renderer::command_queue::submit(command);
    }

    ~sandbox() override = default;
};
