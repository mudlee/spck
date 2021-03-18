#pragma once

#include <queue>

#include <spck/renderer/command/command.hpp>
#include <spck/utils/noncopyable.hpp>

namespace spck {

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