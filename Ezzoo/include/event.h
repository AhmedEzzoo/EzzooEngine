#ifndef EVENT_H
#define EVENT_H
#include "facilities.h"
#include "core.h"
enum EventType
{

    None = 0,
    WindowClose,
    WindowResize,
    WindowLostFocus,
    WindowMoved,
    AppTick,
    AppUpdate,
    AppRender,
    KeyPressed,
    KeyReleased,
    KeytTyped,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled

};

enum EventCategory
{
    none = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryInput = BIT(1),
    EventCategoryKeyboard = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryMouseButton = BIT(4)

};

#define EVENT_CLASS_TYPE(type)                          \
    static EventType get_static_type()                  \
    {                                                   \
        return EventType::type;                         \
    }                                                   \
    virtual EventType get_event_type() const override   \
    {                                                   \
        return get_static_type();                       \
    }                                                   \
    virtual const char *get_event_name() const override \
    {                                                   \
        return #type;                                   \
    }

#define EVENT_CLASS_CATEGORY(category)              \
    virtual int get_event_category() const override \
    {                                               \
        return category;                            \
    }

class Event
{
public:
    virtual EventType get_event_type() const = 0;
    virtual int get_event_category() const = 0;
    virtual const char *get_event_name() const = 0;
    virtual std::string to_string() const { return get_event_name(); }

    bool is_in_categories() { return get_event_category() & m_handled; }
    bool m_handled{false};
    // protected:
};

class EventDispatch
{
    template <typename T>
    using EventFn = std::function<bool(T &)>;

public:
    EventDispatch(Event &event) : m_event(event) {}

    template <typename T>
    bool Dispatch(EventFn<T> fn)
    {
        if (m_event.get_event_type() == T::get_static_type())
        {

            m_event.m_handled = fn(*(T *)&m_event);
            return true;
        }
        return false;
    }

private:
    Event &m_event;
};

inline std::ostream &operator<<(std::ostream &os, const Event &event)
{

    return os << event.to_string();
}

#endif