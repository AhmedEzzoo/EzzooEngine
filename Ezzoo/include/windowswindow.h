#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "glad/glad.h"
#include "window.h"

class WindowsWindow : public Window
{

public:
    WindowsWindow(const WindowProps &props);
    virtual ~WindowsWindow();

    virtual void on_updata() override;
    virtual void *get_native_window() const override { return m_window; }
    virtual unsigned int get_width() const override { return m_data.width; }
    virtual unsigned int get_height() const override { return m_data.height; }
    virtual void set_event_callback(const EventCallFn &event_callback) override { m_data.EventCallback = event_callback; }
    virtual void set_v_sync(bool enable) override;
    virtual bool is_v_sync() const override;

private:
    virtual void init(const WindowProps &props);
    virtual void shutdown();
    GLFWwindow *m_window;
    struct WindowData
    {

        std::string title;
        unsigned int width, height;
        EventCallFn EventCallback;
        bool v_sync;
    };

    WindowData m_data;
};
// #define EZZOO_WINDOW_INFO (x, ...)     EZZOO_CORE_INFO(x,__VA_ARGS__)
#endif