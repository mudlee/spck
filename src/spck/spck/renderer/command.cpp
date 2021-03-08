#include <spck/renderer/command.hpp>

namespace spck {

std::queue<std::shared_ptr<command>> standard_command_queue::commands;

}