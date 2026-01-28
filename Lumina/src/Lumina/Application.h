#pragma once

#include "Core.h"
namespace Lumina
{

class LUMINA_API Application
{
  public:
    Application();
    virtual ~Application();

    void Run();
};

Application* CreateApplication();

} // namespace Lumina
