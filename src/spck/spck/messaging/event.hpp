#pragma once

#include <spck/api.hpp>

#define BIND_EVENT_FN(fn) [this](auto &&...args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace spck {

enum class event_type {
    // Keyboard events
    key_pressed,
    // Application events
    window_closed,
};

#define EVENT_CLASS_TYPE(type) \
    static event_type get_static_type() { return event_type::type; } \
    virtual event_type get_event_type() const override { return get_static_type(); }\
    virtual const char *get_name() const override { return #type; }

class SPCK_API event {
public:
    virtual ~event() = default;

    [[nodiscard]] virtual event_type get_event_type() const = 0;

    [[nodiscard]] virtual const char *get_name() const = 0;

public:
    bool handled = false;
};

class event_dispatcher {
public:
    explicit event_dispatcher(event &ev) : ev(ev) {}

    template <typename T, typename F> bool dispatch(const F &func) {
        if (ev.get_event_type() == T::get_static_type()) {
            ev.handled |= func(static_cast<T &>(ev));
            return true;
        }
        return false;
    }

private:
    event &ev;
};

} // namespace spck
