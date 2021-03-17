#pragma once

#include <spck/utils/noncopyable.hpp>

namespace spck {

class shader : noncopyable {
public:
    enum class data_type {
       FLOAT,
    };

public:
    shader() = default;
    virtual ~shader() = default;

    virtual void start() = 0;
    virtual void stop() = 0;
};

}