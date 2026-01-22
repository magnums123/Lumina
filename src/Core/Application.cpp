#include "Application.h"
#include "Log.h"
#include "RHI/Renderer.h"
#include "Window.h"

namespace Engine
{
Application* Application::s_Instance = nullptr;

Application::Application()

{
    s_Instance = this;
    WindowProps windowProps;
    m_Window = Window::Create(windowProps);
    m_Window->SetEventCallback([this](Event& e) { OnEvent(e); });
    Renderer = RHIRenderer::Create(m_Window);
    Renderer->Init();
    m_LayerStack = new LayerStack();
}

Application::~Application()
{
    delete m_LayerStack;
    delete m_Window;
    delete Renderer;
}

void Application::Run()
{
    while (m_Running)
        {
            for (Layer* layer : *m_LayerStack)
                layer->OnUpdate(0.0f);

            m_Window->OnUpdate();
            m_Window->SwapBuffers();
        }
}

void Application::OnEvent(Event& e)
{
    ENGINE_LOG("event triggered: " << e.GetName());
    EventDispatcher dispatcher(e);

    dispatcher.Dispatch<WindowCloseEvent>(
        [this](WindowCloseEvent& e)
            {
                m_Running = false;
                return true;
            });

    for (Layer* layer : *m_LayerStack)
        {
            layer->OnEvent(e);
            if (e.Handled)
                break;
        }
}

void Application::PushLayer(Layer* layer) { m_LayerStack->PushLayer(layer); }

void Application::PushOverlay(Layer* layer) { m_LayerStack->PushOverlay(layer); }
} // namespace Engine
