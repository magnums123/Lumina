#pragma once
#include "Event.h"
#include <functional>
#include <string>

namespace Engine
{

struct WindowProps
{
    std::string Title = "Engine";
    unsigned int Width = 1280;
    unsigned int Height = 720;
};

class Window
{
  public:
    using EventCallbackFn = std::function<void(Event&)>;

    virtual ~Window() = default;

    virtual void OnUpdate() = 0;
    virtual void SwapBuffers() = 0;
    virtual void* GetProcAddress() = 0;
    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
    virtual void* GetNativeWindow() const = 0;

    static Window* Create(const WindowProps& props);
};

} // namespace Engine
