#pragma once

#include <spck/utils.hpp>
#include <spck/renderer/vertex_array.hpp>

#include <queue>

namespace spck {

class command {
public:
    command() = default;
    ~command() = default;
    DELETE_COPY_METHODS(command)

    virtual void render() = 0;
};

class draw_indexed_command : public command {
public:
    explicit draw_indexed_command(std::shared_ptr<vertex_array> vao): vao(std::move(vao)) {}
    DELETE_COPY_METHODS(draw_indexed_command)

    virtual void render() = 0;

protected:
    std::shared_ptr<vertex_array> vao{};
};

class standard_command_queue {
public:
    standard_command_queue() = delete;
    ~standard_command_queue() = delete;
    DELETE_COPY_METHODS(standard_command_queue)

    static void submit(const std::shared_ptr<command>& command) {
        commands.push(command);
    };

    static void flush() {
        while(!commands.empty()) {
            commands.front()->render();
            commands.pop();
        }
    }

private:
    static std::queue<std::shared_ptr<command>> commands;

};

}