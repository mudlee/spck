#pragma once

#include "event.hpp"

namespace spck {
class window_closed_event : public event {
public:
    EVENT_CLASS_TYPE(window_closed)
};
} // namespace spck