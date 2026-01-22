#pragma once
#include "Core/Application.h"
#include <Core/Layer.h>
#include <glad/glad.h>

class GameLayer : public Engine::Layer
{
  private:
    Engine::Application* app;

  public:
    GameLayer() : Layer("GameLayer") {}

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(float dt) override;
    void OnEvent(Engine::Event& e) override;
};
