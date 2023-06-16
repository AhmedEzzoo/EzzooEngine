#ifndef IMGUI_LAYER_H
#define IMGUI_LAYER_H

#include "layer.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "GLFW/glfw3.h"
class IamGuiLayer : public Layer
{

public:
    IamGuiLayer();
    ~IamGuiLayer();

    virtual void on_attach() override;
    virtual void on_detach() override;
    virtual void on_imgui_render() override;

    void Begin();
    void End();

private:
    float m_time{0.0f};
};

#endif