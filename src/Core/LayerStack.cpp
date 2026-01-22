#include "LayerStack.h"

namespace Lumina
{

LayerStack::~LayerStack()
{
    for (Layer* layer : *this)
        {
            layer->OnDetach();
            delete layer;
        }
}

void LayerStack::PushLayer(Layer* layer)
{
    m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
    m_LayerInsertIndex++;
    layer->OnAttach();
}

void LayerStack::PushOverlay(Layer* overlay)
{
    m_Layers.emplace_back(overlay);
    overlay->OnAttach();
}

} // namespace Lumina
