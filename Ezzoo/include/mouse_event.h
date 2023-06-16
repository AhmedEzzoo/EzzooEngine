#pragma Once
#include <sstream>
#include "event.h"
#include "mouse_codes.h"

class MouseButtonEvent : public Event
{

public:
    MouseCodes get_mouse_button() const { return m_button; }

    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
protected:
    MouseButtonEvent(const MouseCodes button)
        : m_button(button) {}

    MouseCodes m_button;
};

class MouseButtonClickedEvent : public MouseButtonEvent
{

public:
    MouseButtonClickedEvent(const MouseCodes button) : MouseButtonEvent(button) {}
    std::string to_string() const override
    {

        std::stringstream ss;

        ss << "Mouse Pressed Event : " << m_button;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonPressed);
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{

public:
    MouseButtonReleasedEvent(const MouseCodes button) : MouseButtonEvent(button) {}
    std::string to_string() const override
    {

        std::stringstream ss;

        ss << "Mouse Released Event : " << m_button;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonReleased);
};

class MouseMovedEvent : public Event
{

public:
    MouseMovedEvent(float x, float y) : m_x_mouse(x), m_y_mouse(y) {}

    std::string to_string() const override
    {

        std::stringstream ss;

        ss << "Mouse position  => X : " << m_x_mouse << ", y : " << m_y_mouse;
        return ss.str();
    }

    float get_x() const { return m_x_mouse; }
    float get_y() const { return m_y_mouse; }

    EVENT_CLASS_TYPE(MouseMoved);
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

private:
    float m_x_mouse;
    float m_y_mouse;
};

class MouseScrolledEvent : public Event
{
public:
    MouseScrolledEvent(float x_offset, float y_offset) : m_x_offset(x_offset), m_y_offset(y_offset) {}

    std::string to_string() const override
    {

        std::stringstream ss;

        ss << "Mouse scrolled  => Xoffset : " << m_x_offset << ", yoffset : " << m_y_offset;
        return ss.str();
    }
    float get_xOffset() const { return m_x_offset; }
    float get_yOffset() const { return m_y_offset; }

    EVENT_CLASS_TYPE(MouseScrolled);
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

private:
    float m_x_offset;
    float m_y_offset;
};
