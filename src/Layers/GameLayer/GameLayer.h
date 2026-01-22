#pragma once
#include "Scene/Camera.h"
#include <Core/Application.h>
#include <Core/Layer.h>
#include <Scene/Scene.h>
#include <Scene/Vertex.h>
#include <glad/glad.h>
#include <vector>

namespace Lumina
{
class GameLayer : public Layer
{
  private:
    Lumina::Application* app;

    Shader* testShader = nullptr;
    std::vector<Vertex> vertices{
        {{-0.5f, -0.5f, 0.0f}}, {{0.5f, -0.5f, 0.0f}}, {{0.0f, 0.5f, 0.0f}}};
    Mesh triangleMesh{vertices, testShader};

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
