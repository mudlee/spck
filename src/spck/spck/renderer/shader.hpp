#pragma once

namespace spck {

class shader {
public:
    shader() = default;
    ~shader() = default;
    shader(const shader &) = delete;
    shader &operator=(const shader &) = delete;

    virtual void start() = 0;
    virtual void stop() = 0;
};

}