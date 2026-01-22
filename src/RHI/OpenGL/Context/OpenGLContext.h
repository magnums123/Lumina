#pragma once
#include <Core/Window.h>
#include <RHI/Context.h>
namespace Engine
{

class OpenGLContext : public RHIContext
{
  public:
    OpenGLContext(Window* windowHandle);

    void Init() override;

  private:
    Window* m_WindowHandle;
};

} // namespace Engine
