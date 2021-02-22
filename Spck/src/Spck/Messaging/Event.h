#pragma once

#include "Spck/API.h"

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Spck
{
    enum class EventType
    {
        // Keyboard events
        KeyPressed,
        // Application events
        WindowClosed,
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

    class SPCK_API Event
    {
    public:
        virtual ~Event() = default;

        [[nodiscard]] virtual EventType GetEventType() const = 0;

        [[nodiscard]] virtual const char* GetName() const = 0;
    public:
        bool Handled = false;
    };

    class EventDispatcher
    {
    public:
        explicit EventDispatcher(Event& event): m_Event(event){}

        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };
}
