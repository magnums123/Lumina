#pragma once
#include <Core/Window.h>

namespace Lumina
{

class RHIContext
{
  public:
    virtual ~RHIContext() = default;
    virtual void Init() = 0;
    static RHIContext* Create(Window* windowHandle);
};

} // namespace Lumina
