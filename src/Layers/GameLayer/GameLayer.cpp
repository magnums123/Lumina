#include "Core/Event.h"
#include <Core/Application.h>
#include <Core/Log.h>
#include <GLFW/glfw3.h>
#include <Layers/GameLayer/GameLayer.h>
#include <vector>

namespace Lumina
{

std::vector<Vertex> vertices{{{0.5f, 0.5f, 0.0f}}, {{0.5f, -0.5f, 0.0f}},
    {{-0.5f, -0.5f, 0.0f}}, {{-0.5f, 0.5f, 0.0f}}};
std::vector<unsigned int> indices = {0, 1, 3, 1, 2, 3};

void GameLayer::OnAttach()
{
    app = Application::Get();
    testShader = new Shader("test_vert.glsl", "test_frag.glsl");
    triangleMesh = new Mesh{vertices, indices, *testShader};
    testScene.meshes.push_back(*triangleMesh);
    ENGINE_LOG(this->GetName() << " attached");
}

void GameLayer::OnDetach()
{
    app = nullptr;
    testShader = nullptr;
    delete triangleMesh;
    ENGINE_LOG("GameLayer detached");
}

void GameLayer::OnUpdate(float dt)
{
    if (triangleMesh && testShader)
        app->Renderer->SubmitScene(testScene);
}

void GameLayer::OnEvent(Event& e)
{
    EventDispatcher dispatcher(e);

    dispatcher.Dispatch<KeyPressEvent>(
        [this](KeyPressEvent& e)
            {
                ENGINE_LOG("event triggered: " << e.GetName() << " From: " << GetName());
                ENGINE_LOG("Event key is: " << e.key);

                if (e.key == GLFW_KEY_ESCAPE)
                    {
                        ENGINE_LOG("Recording key input from: " << GetName());
                    }
                if (e.key == GLFW_KEY_Q)
                    {
                        ENGINE_LOG("Recording key input from: " << GetName());
                    }
                return true;
            });
}
} // namespace Lumina
