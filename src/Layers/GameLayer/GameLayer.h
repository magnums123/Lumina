#pragma once
#include "Scene/Camera.h"
#include <Core/Application.h>
#include <Core/Layer.h>
#include <Scene/Scene.h>
#include <Scene/Vertex.h>
#include <glad/glad.h>

namespace Lumina
{
class GameLayer : public Layer
{
  private:
    Lumina::Application* app;

    Shader* testShader = nullptr;
    Mesh* triangleMesh = nullptr;

    Camera camera{75.f, 1920, 1080};
    Scene testScene{camera};

  public:
    GameLayer(const char* name = "GameLayer") : Layer(name) {}
    ~GameLayer() override {}

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(float dt) override;
    void OnEvent(Event& e) override;
};
} // namespace Lumina
