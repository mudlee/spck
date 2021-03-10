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

    virtual void start() const = 0;
    virtual void stop() const = 0;
};

}