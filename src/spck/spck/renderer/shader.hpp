#pragma once

#include <spck/utils.hpp>

namespace spck {

class shader {
public:
    enum class data_type {
       FLOAT,
    };

public:
    shader() = default;
    ~shader() = default;
    DELETE_COPY_METHODS(shader)

    virtual void start() const = 0;
    virtual void stop() const = 0;
};

}