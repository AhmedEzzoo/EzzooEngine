#ifndef LAYER_H
#define LAYER_H
#include "facilities.h"

class Event;
class Layer
{
    friend std::ostream &operator<<(std::ostream &os, const Layer &layer);

public:
    Layer(std::string title) : m_title(title) {}
    virtual ~Layer();
    virtual void on_attach() {}
    virtual void on_detach() {}
    virtual void on_update() {}
    virtual void on_event(Event &e) {}
    virtual void on_imgui_render() {}

    const std::string &get_title() const { return m_title; }

private:
    std::string m_title{"any title"};
};

inline std::ostream &operator<<(std::ostream &os, const Layer &layer)
{

    return os << layer.m_title;
}

#endif // LAYER_H
