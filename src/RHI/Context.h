#pragma once
#include <Core/Window.h>

namespace Engine
{

class RHIContext
{
  public:
    virtual ~RHIContext() = default;
    virtual void Init() = 0;
    static RHIContext* Create(Window* windowHandle);
};

} // namespace Engine
