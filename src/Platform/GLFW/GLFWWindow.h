#pragma once
#include "../../Core/Window.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Engine
{

class GLFWWindow : public Window
{
  public:
    GLFWWindow(const WindowProps& props);
    virtual ~GLFWWindow();

    void OnUpdate() override;
    void SwapBuffers() override;
    void* GetProcAddress() override;

    unsigned int GetWidth() const override { return m_Data.Width; }
    unsigned int GetHeight() const override { return m_Data.Height; }

    void SetEventCallback(const EventCallbackFn& callback) override
    {
        m_Data.EventCallback = callback;
    }

    void* GetNativeWindow() const override { return m_Window; }

  private:
    void Init(const WindowProps& props);
    void Shutdown();

    GLFWwindow* m_Window;

    struct WindowData
    {
        std::string Title;
        unsigned int Width, Height;
        EventCallbackFn EventCallback;
    };

    WindowData m_Data;
};

} // namespace Engine
