#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.h"
#include "key_event.h"
#include "window_event.h"
#include "mouse_event.h"

#include "layer_container.h"
#include "imgui_layer.h"
class Application
{

public:
    Application();
    ~Application();
    void run();
    void on_event(Event &e);
    void push_layer(Layer *layer);
    void push_overlay(Layer *layer);

    static Application &Get() { return *s_instance; }
    Window &get_window() { return *m_window; }

private:
    bool on_window_close_event(WindowCloseEvent &e);
    bool on_window_resize(WindowResizeEvent &e);
    bool on_key_pressed(KeyPressedEvent &key);
    bool on_mouse_button_pressed(MouseButtonClickedEvent &e);
    bool on_mouse_button_Released(MouseButtonReleasedEvent &e);
    bool on_mouse_moved(MouseMovedEvent &e);
    bool on_mouse_scrolled(MouseScrolledEvent &e);

private:
    bool m_running{true};
    std::unique_ptr<Window> m_window;
    LayerContainer m_layerContainer;
    IamGuiLayer *m_imGuiLayer;
    static Application *s_instance;
};

Ref<Application> create_application();

#endif