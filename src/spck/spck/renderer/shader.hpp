#pragma once

namespace spck {

class shader {
public:
    enum class data_type {
       FLOAT,
    };

public:
    shader() = default;
    ~shader() = default;
    shader(const shader &) = delete;
    shader &operator=(const shader &) = delete;

    virtual void start() const = 0;
    virtual void stop() const = 0;
};

}