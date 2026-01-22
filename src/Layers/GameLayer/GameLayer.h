#pragma once
#include "Core/Application.h"
#include <Core/Layer.h>
#include <glad/glad.h>

class GameLayer : public Lumina::Layer
{
  private:
    Lumina::Application* app;

  public:
    GameLayer() : Layer("GameLayer") {}

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(float dt) override;
    void OnEvent(Lumina::Event& e) override;
};
