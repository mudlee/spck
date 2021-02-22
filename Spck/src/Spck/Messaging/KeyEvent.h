#pragma once

#include "Event.h"

namespace Spck
{
    class KeyEvent : public Event
    {
    public:
        int& GetKeyCode() { return m_KeyCode; };

    protected:
        explicit KeyEvent(const int keyCode):m_KeyCode(keyCode){}

    protected:
        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        explicit KeyPressedEvent(const int keyCode): KeyEvent(keyCode){}

        EVENT_CLASS_TYPE(KeyPressed)
    };
}
