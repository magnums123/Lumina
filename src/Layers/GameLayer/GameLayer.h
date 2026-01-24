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
    Application* app;

    Shader* testShader = nullptr;
    Mesh* triangleMesh = nullptr;

    std::vector<Vertex> vertices{{{0.5f, 0.5f, 0.0f}}, {{0.5f, -0.5f, 0.0f}},
        {{-0.5f, -0.5f, 0.0f}}, {{-0.5f, 0.5f, 0.0f}}};
    std::vector<unsigned int> indices = {0, 1, 3, 1, 2, 3};

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
