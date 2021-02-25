#pragma once

#include "event.hpp"

namespace spck {
class key_event : public event {
public:
    int &get_key_code() { return key_code; };

protected:
    explicit key_event(const int key_code) : key_code(key_code) {}

protected:
    int key_code;
};

class key_pressed_event : public key_event {
public:
    explicit key_pressed_event(const int key_code) : key_event(key_code) {}

    EVENT_CLASS_TYPE(key_pressed)
};
} // namespace spck
