#include "Ezzoo.h"

class ExampleLayer : public Layer
{

public:
    ExampleLayer() : Layer("Example Layer") {}
    virtual void on_attach() override
    {
    }
    virtual void on_detach() override
    {
    }
    virtual void on_update() override
    {
        // EZZOO_CLIENT_INFO("{0} Updated", get_title());
    }
    virtual void on_event(Event &e) override
    {
        EZZOO_CLIENT_TRACE("{0} Event from {1}", e, get_title());
    }

private:
};
class SandBox : public Application
{

public:
    SandBox()
    {
        push_layer(new ExampleLayer());
    }
    ~SandBox()
    {
        EZZOO_CLIENT_INFO("Sand Box Destructor Called");
    }
};

Ref<Application> create_application()
{

    return createRef<SandBox>();
}