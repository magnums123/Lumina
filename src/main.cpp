#include "Core/Application.h"
#include "Layers/GameLayer/GameLayer.h"

namespace Lumina
{

class Sandbox : public Application
{
  public:
    Sandbox() { PushLayer(new GameLayer()); }
    ~Sandbox() {}
};
} // namespace Lumina

int main()
{
    Lumina::Sandbox app;
    app.Run();
}
