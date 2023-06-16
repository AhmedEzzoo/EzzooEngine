#include "layer_container.h"
#include "log.h"
// Definitions
// Constructors and destructor

LayerContainer::LayerContainer(const LayerContainer &layers)
{
    if (this == &layers)
        return;
    std::for_each(layers.m_layers.begin(), layers.m_layers.end(), [this](Layer *layer)
                  {
        *(this->m_layers.begin() + this->m_indx_of_layer) = layer;
        this->m_indx_of_layer ++; });
}

LayerContainer::LayerContainer(LayerContainer &&layers)
{
    std::for_each(layers.m_layers.begin(), layers.m_layers.end(), [this](auto layer)
                  {
        *(this->m_layers.begin() + this->m_indx_of_layer) = layer;
        this->m_indx_of_layer ++; });

    for (Layer *layer : layers.m_layers)
    {

        delete[] layer;
        layer = nullptr;
    }
    m_indx_of_layer = 0;
}

LayerContainer::~LayerContainer()
{
    for (Layer *layer : m_layers)
    {
        EZZOO_CORE_INFO("{0} Layer Destructor Called", layer->get_title());
        delete[] layer;
        layer = nullptr;
    }
    m_indx_of_layer = 0;
}

// methods
void LayerContainer::push_item(Layer *layer)
{
    m_layers.emplace(m_layers.begin() + m_indx_of_layer, layer);
    m_indx_of_layer++;
}

void LayerContainer::push_overlay(Layer *layer)
{
    m_layers.emplace_back(layer);
}

void LayerContainer::pop_item(Layer *layer)
{
    auto it = std::find(m_layers.begin(), m_layers.begin() + m_indx_of_layer, layer);
    if (it != (m_layers.begin() + m_indx_of_layer))
    {

        m_layers.erase(it);
        m_indx_of_layer--;
    }
}

void LayerContainer::pop_overlay(Layer *layer)
{
    auto it = std::find(m_layers.begin(), m_layers.end(), layer);

    if (it != m_layers.end())
    {

        m_layers.erase(it);
    }
}

// operators
void LayerContainer::operator+(LayerContainer &layers)
{
    m_indx_of_layer += layers.m_indx_of_layer;
    std::transform(layers.m_layers.begin(), layers.m_layers.end(), std::back_inserter(m_layers), [](Layer *layer)
                   { return layer; });
}

void LayerContainer::operator+=(const LayerContainer &layers)
{
}

void LayerContainer::operator=(LayerContainer &layers)
{
}

void LayerContainer::operator++(int increment_val)
{
}

std::ostream &operator<<(std::ostream &os, const LayerContainer &layers)
{

    os << "Vector is : [";

    for (Layer *layer : layers.m_layers)
    {

        os << " " << *layer;
    }

    os << " ]";

    return os;
}