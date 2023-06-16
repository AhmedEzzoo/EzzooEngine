#include "windows_input.h"
#include "GLFW/glfw3.h"

Input *Input::s_instance = new WindowsInput();

bool WindowsInput::is_key_pressed_impl(int key_code)
{
    auto window = static_cast<GLFWwindow *>(Application::Get().get_window().get_native_window());
    int state = glfwGetKey(window, key_code);

    return state == GLFW_PRESS || state == GLFW_REPEAT;
}
std::pair<float, float> WindowsInput::get_mouse_pos_impl()
{
    auto window = static_cast<GLFWwindow *>(Application::Get().get_window().get_native_window());
    double xPos, yPos;
    glfwGetCursorPos(window, &xPos, &yPos);

    return {(float)xPos, (float)yPos};
}
float WindowsInput::get_mouse_x_impl()
{
    auto [x, y] = get_mouse_pos_impl();

    return x;
}
float WindowsInput::get_mouse_y_impl()
{
    auto [x, y] = get_mouse_pos_impl();

    return y;
}