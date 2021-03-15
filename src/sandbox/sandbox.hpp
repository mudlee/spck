#pragma once

#include <spck/spck.hpp>

class sandbox : public spck::application {
public:
    sandbox() {
        SPCK_LOG_DEBUG("Starting up sandbox");

        const float vertices[] = {
            -0.5f,  0.5f, 0.0f, // vertex 1
            -0.5f, -0.5f, 0.0f, // vertex 2
            0.5f, -0.5f, 0.0f, // vertex 3
            0.5f,  0.5f, 0.0f, // vertex 4
        };

        const int indices[] = {
            0, 1, 3, 3, 1, 2,
        };

        const char* vertex_source = "#version 410 core\n"
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

        shader = std::make_unique<spck::renderer::shader>(vertex_source, fragment_source);

        spck::vertex_layout_attribute attrib{
            3,
            spck::shader::data_type::FLOAT,
            false,
            3 * sizeof(float),
            nullptr
        };

        auto layout = std::make_shared<spck::vertex_buffer_layout>(
            std::vector<spck::vertex_layout_attribute> {attrib}
        );

        vao = std::make_shared<spck::renderer::vertex_array>();
        spck::renderer::vertex_buffer vbo(vertices, sizeof(vertices), layout);
        spck::renderer::index_buffer ebo(indices, sizeof(indices));

        vao->add_vbo(vbo);
        vao->set_ebo(ebo);
    }

    ~sandbox() override = default;

    void on_begin_frame() override {
        shader->start(); // note: shader binding will be moved out from here, when we have materials/default material
    }

    void on_update() override {
        command_queue.submit(std::make_shared<spck::renderer::draw_indexed_command>(vao));
    }

    void on_end_frame() override {
        shader->stop();
    }

private:
    std::shared_ptr<spck::renderer::vertex_array> vao;
    std::unique_ptr<spck::renderer::shader> shader;
};
