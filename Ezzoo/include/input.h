#pragma once
#include "facilities.h"
class Input
{

public:
    static bool is_key_pressed(int key_code) { return s_instance->is_key_pressed_impl(key_code); }
    static std::pair<float, float> get_mouse_pos() { return s_instance->get_mouse_pos_impl(); }
    static float get_mouse_x() { return s_instance->get_mouse_x_impl(); }
    static float get_mouse_y() { return s_instance->get_mouse_y_impl(); }

protected:
    virtual bool is_key_pressed_impl(int key_code) = 0;
    virtual std::pair<float, float> get_mouse_pos_impl() = 0;
    virtual float get_mouse_x_impl() = 0;
    virtual float get_mouse_y_impl() = 0;

private:
    static Input *s_instance;
};