#include <Core/Application.h>
#include <Core/Log.h>
#include <Layers/GameLayer/GameLayer.h>

namespace Lumina
{
void GameLayer::OnAttach()
{
    app = Lumina::Application::Get();
    testShader = new Shader("test_vert.glsl", "test_frag.glsl");
    triangleMesh = {vertices, testShader};
    testScene.meshes.push_back(triangleMesh);
    ENGINE_LOG(this->GetName() << " attached");
}

void GameLayer::OnDetach()
{
    app = nullptr;
    testShader = nullptr;
    ENGINE_LOG("GameLayer detached");
}

void GameLayer::OnUpdate(float dt)
{
    app->Renderer->StartFrame();
    app->Renderer->SubmitScene(testScene);
    app->Renderer->EndFrame();
}

void GameLayer::OnEvent(Event& e)
{
    // Handle input/events here
}
} // namespace Lumina
