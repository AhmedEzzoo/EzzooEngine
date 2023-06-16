#pragma once
#include "event.h"
#include <sstream>
class WindowCloseEvent : public Event
{

public:
    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "Window Closed event";

        return ss.str();
    }

    EVENT_CLASS_TYPE(WindowClose);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
};

class WindowResizeEvent : public Event
{

public:
    WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

    std::string to_string() const override
    {

        std::stringstream ss;
        ss << "Window Size is  : [ Width : " << m_width << ", Height : " << m_height << " ]";
        return ss.str();
    }

    unsigned int get_width() const { return m_width; }
    unsigned int get_height() const { return m_height; }
    EVENT_CLASS_TYPE(WindowResize);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);

private:
    unsigned int m_width{0};
    unsigned int m_height{0};
};