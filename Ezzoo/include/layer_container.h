#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H

#include "Layer.h"

class LayerContainer
{

    friend std::ostream &operator<<(std::ostream &os, const LayerContainer &layers);

public:
    // Constructors and Destructor
    LayerContainer() = default;
    LayerContainer(const LayerContainer &layers);
    LayerContainer(LayerContainer &&layers);
    ~LayerContainer();

    // methods
    void push_item(Layer *layer);
    void push_overlay(Layer *layer);
    void pop_item(Layer *layer);
    void pop_overlay(Layer *layer);
    unsigned int get_index() const { return m_indx_of_layer; }

    // iterators
    std::vector<Layer *>::iterator end() { return m_layers.end(); }
    std::vector<Layer *>::iterator begin() { return m_layers.begin(); }
    std::vector<Layer *>::reverse_iterator rbegin() { return m_layers.rbegin(); }
    std::vector<Layer *>::reverse_iterator rend() { return m_layers.rend(); }
    std::vector<Layer *>::const_iterator cbegin() { return m_layers.cbegin(); }
    std::vector<Layer *>::const_iterator cend() { return m_layers.cend(); }

    // operators
    void operator+=(const LayerContainer &layers);
    void operator+(LayerContainer &layers);
    void operator=(LayerContainer &layers);
    void operator++(int increment_val);

private:
    std::vector<Layer *> m_layers;
    unsigned int m_indx_of_layer{0};
};

#endif