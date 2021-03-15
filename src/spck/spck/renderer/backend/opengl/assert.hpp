#pragma once

#include <exception>
#include <string>
#include <utility>

namespace spck {

class opengl_exception: public std::exception
{
public:
    explicit opengl_exception(std::string& message): message(std::move(message)){}

private:
    std::string message;
};

int lofasz(int result) {
    if(result == 0) {
        std::string message = "OpenGL command failed with a result of ";
        message += std::to_string(result);
        throw opengl_exception(message);
    }
    return result;
}

}
