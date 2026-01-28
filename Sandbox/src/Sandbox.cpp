#include <Lumina.h>

class Sandbox : public Lumina::Application
{
  public:
    Sandbox() {}

    ~Sandbox() {}
};

Lumina::Application* Lumina::CreateApplication() { return new Sandbox(); }
