#pragma once
#include "Event.h"

namespace Lumina
{

class Layer
{
  public:
    Layer(const char* name = "Layer") : m_Name(name) {}
    virtual ~Layer() = default;

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate(float dt) {}
    virtual void OnEvent(Event& e) {}

    const char* GetName() const { return m_Name; }

  protected:
    const char* m_Name;
};

} // namespace Lumina
