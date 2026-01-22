#include "Core/Application.h"
#include "Layers/GameLayer/GameLayer.h"

class Sandbox : public Engine::Application
{
  public:
    Sandbox() { PushLayer(new GameLayer()); }
    ~Sandbox() {}
};

int main()
{
    Sandbox app;
    app.Run();
}
