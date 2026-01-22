#include "GameLayer.h"
#include "Core/Application.h"
#include "Core/Log.h"
#include <iterator>

void GameLayer::OnAttach()
{
    app = Engine::Application::Get();
    ENGINE_LOG("GameLayer attached");
}

void GameLayer::OnDetach()
{
    app = nullptr;
    ENGINE_LOG("GameLayer detached");
}

void GameLayer::OnUpdate(float dt)
{
    app->Renderer->StartFrame();
    app->Renderer->EndFrame();
}

void GameLayer::OnEvent(Engine::Event& e)
{
    // Handle input/events here
}
