#pragma once

#include <spck/utils/noncopyable.hpp>

namespace spck {

class command : noncopyable {
public:
    command() = default;
    virtual ~command() = default;

    virtual void render() = 0;
};

}