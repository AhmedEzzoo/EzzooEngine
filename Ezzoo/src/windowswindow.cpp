#include "windowswindow.h"
#include "log.h"
#include "key_event.h"
#include "window_event.h"
#include "mouse_event.h"

static bool s_GLFW_init{false};
Window *Window::create_window(const WindowProps &props)
{

        return new WindowsWindow(props);
}

WindowsWindow::WindowsWindow(const WindowProps &props)
{

        init(props);
}
WindowsWindow::~WindowsWindow()
{
        EZZOO_CORE_INFO("WIndows Window Destructor called");
        shutdown();
}

void WindowsWindow::init(const WindowProps &props)
{

        m_data.title = props.m_title;
        m_data.width = props.m_width;
        m_data.height = props.m_height;

        EZZOO_CORE_INFO("Creating Window {0}, {1}, {2}", props.m_title, props.m_height, props.m_width);

        if (!s_GLFW_init)
        {

                int success = glfwInit();

                s_GLFW_init = true;
        }

        m_window = glfwCreateWindow(props.m_width, props.m_height, props.m_title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status)
                EZZOO_CORE_ERROR("GLAD failed to initialize");
        EZZOO_CORE_INFO("Status of GLAD is : {0}", status);
        glfwSetWindowUserPointer(m_window, &m_data);
        set_v_sync(true);

        glfwSetKeyCallback(m_window,
                           [](GLFWwindow *window, int key, int scancode, int action, int mods)
                           {
                                WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
                                switch(action){

                                case GLFW_PRESS :
                                {
                                        KeyPressedEvent event (key, 0);
                                        data.EventCallback(event);
                                        break;           
                                } 
                                  case GLFW_RELEASE :
                                {
                                        KeyReleasedEvent event (key);
                                        data.EventCallback(event);
                                        break;           
                                } 
                                case GLFW_REPEAT :
                                {
                                        KeyPressedEvent event (key, 10);
                                        data.EventCallback(event);
                                        break;           
                                }
                        } });

        glfwSetCharCallback(m_window, [](GLFWwindow *window, unsigned int keyCode)
                            {
                                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                                KeyTypedEvent e(keyCode);
                                data.EventCallback(e); });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window)
                                   {
                                        WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
                                        WindowCloseEvent e;
                                        data.EventCallback(e) ; });

        glfwSetWindowSizeCallback(m_window, [](GLFWwindow *window, int width, int height)
                                  {
                                        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                        WindowResizeEvent e(width, height);
                                        data.EventCallback(e); });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow *window, int button, int action, int mods)
                                   {
                                        WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                        switch (action)
                                        {

                                        case GLFW_PRESS:
                                        {
                                                   MouseButtonClickedEvent event(button);
                                                   data.EventCallback(event);
                                                   break;
                                        }
                                        case GLFW_RELEASE:
                                        {
                                                  MouseButtonReleasedEvent event(button);
                                                   data.EventCallback(event);
                                                   break;
                                        }
                                        } });
        glfwSetCursorPosCallback(m_window, [](GLFWwindow *window, double xpos, double ypos)
                                 {
                                         WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                         MouseMovedEvent e((float)xpos, (float)ypos);
                                         data.EventCallback(e); });

        glfwSetScrollCallback(m_window, [](GLFWwindow *window, double xoffset, double yoffset)
                              {
                                         WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                         MouseScrolledEvent e(xoffset, yoffset);
                                         data.EventCallback(e); });
}

void WindowsWindow::shutdown()
{

        glfwDestroyWindow(m_window);
}

void WindowsWindow::on_updata()
{
        glfwPollEvents();
        glfwSwapBuffers(m_window);
}

void WindowsWindow::set_v_sync(bool enable)
{

        if (enable)
        {

                glfwSwapInterval(1);
        }
        else
        {

                glfwSwapInterval(0);
        }

        m_data.v_sync = enable;
}
bool WindowsWindow::is_v_sync() const
{

        return m_data.v_sync;
}