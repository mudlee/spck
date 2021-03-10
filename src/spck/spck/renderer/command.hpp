#pragma once

#include <spck/renderer/vertex_array.hpp>
#include <spck/utils/noncopyable.hpp>

#include <queue>

namespace spck {

class command : noncopyable {
public:
    command() = default;
    virtual ~command() = default;

    virtual void render() = 0;
};

class draw_indexed_command : public command {
public:
    explicit draw_indexed_command(std::shared_ptr<vertex_array> vao): vao(std::move(vao)) {}

    void render() override = 0;

protected:
    std::shared_ptr<vertex_array> vao;
};

class standard_command_queue : noncopyable {
public:
    standard_command_queue() = default;
    ~standard_command_queue() = default;

    void submit(const std::shared_ptr<command>& command) {
        commands.push(command);
    };

    void flush() {
        while(!commands.empty()) {
            commands.front()->render();
            commands.pop();
        }
    }

private:
    std::queue<std::shared_ptr<command>> commands{};

};

}