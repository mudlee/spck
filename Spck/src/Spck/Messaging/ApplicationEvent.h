#pragma once

#include "Event.h"

namespace Spck
{
    class WindowClosedEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(WindowClosed)
    };
}