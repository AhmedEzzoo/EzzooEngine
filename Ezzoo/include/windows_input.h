#pragma once

#include "input.h"
#include "application.h"
class WindowsInput : public Input
{

protected:
    virtual bool is_key_pressed_impl(int key_code) override;
    virtual std::pair<float, float> get_mouse_pos_impl() override;
    virtual float get_mouse_x_impl() override;
    virtual float get_mouse_y_impl() override;
};