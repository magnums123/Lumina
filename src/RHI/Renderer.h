#pragma once
#include <Core/Window.h>
#include <RHI/Context.h>

namespace Engine
{
class RHIRenderer
{
  protected:
    RHIContext* context;

  public:
    RHIRenderer() = default;
    virtual ~RHIRenderer() = default;

    virtual void Init() = 0;
    virtual void StartFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Destroy() = 0;

    static RHIRenderer* Create(Window* windowHandle);
};
} // namespace Engine
