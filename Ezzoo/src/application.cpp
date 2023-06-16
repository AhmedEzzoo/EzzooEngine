#include "application.h"
#include "log.h"
#include "layer_container.h"
#include "input.h"

#define BIND_APP_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

Application *Application::s_instance = nullptr;
Application::Application()
{

    s_instance = this;
    m_window = std::unique_ptr<Window>(Window::create_window());
    m_window->set_event_callback(BIND_APP_FUNCTION(on_event));
    m_imGuiLayer = new IamGuiLayer();

    push_overlay(m_imGuiLayer);
    // EZZOO_ASSERT(s_instance, "App object already exist");
}
Application::~Application()
{

    EZZOO_CORE_INFO("Application Destructor Called");
}

void Application::run()
{

    while (m_running)
    {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for (Layer *layer : m_layerContainer)
            layer->on_update();

        m_imGuiLayer->Begin();
        for (Layer *layer : m_layerContainer)
            layer->on_imgui_render();

        m_imGuiLayer->End();
        m_window->on_updata();
    }
}

void Application::on_event(Event &e)
{

    EventDispatch dispatcher(e);
    // dispatcher.Dispatch<KeyPressedEvent>(BIND_APP_FUNCTION(on_key_pressed));
    dispatcher.Dispatch<WindowCloseEvent>(BIND_APP_FUNCTION(on_window_close_event));
    dispatcher.Dispatch<WindowResizeEvent>(BIND_APP_FUNCTION(on_window_resize));
    // dispatcher.Dispatch<MouseButtonClickedEvent>(BIND_APP_FUNCTION(on_mouse_button_pressed));
    // dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_APP_FUNCTION(on_mouse_button_Released));
    // dispatcher.Dispatch<MouseMovedEvent>(BIND_APP_FUNCTION(on_mouse_moved));
    // dispatcher.Dispatch<MouseScrolledEvent>(BIND_APP_FUNCTION(on_mouse_scrolled));
    EZZOO_CORE_TRACE("{0}", e);
    for (auto it = m_layerContainer.end(); it != m_layerContainer.begin();)
    {

        (*--it)->on_event(e);

        if (e.m_handled)
            break;
    }
}

void Application::push_layer(Layer *layer)
{
    m_layerContainer.push_item(layer);
    layer->on_attach();
}
void Application::push_overlay(Layer *layer)
{
    m_layerContainer.push_overlay(layer);
    layer->on_attach();
}

bool Application::on_key_pressed(KeyPressedEvent &key)
{
    // EZZOO_CLIENT_INFO("{0}", key);
    return true;
}

bool Application::on_window_close_event(WindowCloseEvent &e)
{

    m_running = false;
    return true;
}

bool Application::on_window_resize(WindowResizeEvent &e)
{

    return true;
}

bool Application::on_mouse_button_pressed(MouseButtonClickedEvent &e)
{
    return true;
}
bool Application::on_mouse_button_Released(MouseButtonReleasedEvent &e)
{

    return true;
}

bool Application::on_mouse_moved(MouseMovedEvent &e)
{

    return true;
}
bool Application::on_mouse_scrolled(MouseScrolledEvent &e)
{

    return true;
}