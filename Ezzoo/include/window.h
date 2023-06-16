#ifndef WINDOW_H
#define WINDOW_H

#include "event.h"
#include "GLFW/glfw3.h"

struct WindowProps
{

    std::string m_title;
    unsigned int m_width;
    unsigned int m_height;

    WindowProps(const std::string &title = "Ezzoo Engine", unsigned int width = 1280, unsigned int height = 720)
        : m_title(title), m_width(width), m_height(height)
    {
    }
};

class Window
{

public:
    using EventCallFn = std::function<void(Event &)>;
    virtual ~Window(){};
    virtual void on_updata() = 0;
    virtual void *get_native_window() const = 0;
    virtual unsigned int get_width() const = 0;
    virtual unsigned int get_height() const = 0;
    virtual void set_event_callback(const EventCallFn &event) = 0;
    virtual void set_v_sync(bool enable) = 0;
    virtual bool is_v_sync() const = 0;

    static Window *create_window(const WindowProps &window = WindowProps());
};

#endif