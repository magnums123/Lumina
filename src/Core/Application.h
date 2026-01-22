#pragma once
#include "LayerStack.h"
#include "Window.h"
#include <RHI/Renderer.h>

namespace Lumina
{
class Application
{
  public:
    Application();
    virtual ~Application();

    RHIRenderer* Renderer;

    void Run();
    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* layer);

    Window* GetWindow() { return m_Window; }
    static Application* Get() { return s_Instance; }

  private:
    bool m_Running = true;

    static Application* s_Instance;

    Window* m_Window;
    LayerStack* m_LayerStack;
};

} // namespace Lumina
