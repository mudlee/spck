#pragma once

#include <string>

namespace spck {

class opengl_exception: public std::runtime_error
{
public:
    explicit opengl_exception(const std::string& message) : runtime_error(message) {}
    [[nodiscard]] const char* what() const _NOEXCEPT override { return message.c_str(); }

private:
    std::string message;
};

inline int assertGl(int result) {
    if(result == 0) {
        std::string message = "OpenGL command failed with a result of ";
        message += std::to_string(result);
        throw opengl_exception(message);
    }
    return result;
}

}
