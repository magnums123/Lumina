#include <Core/Application.h>
#include <Core/Log.h>
#include <GLFW/glfw3.h>
#include <Layers/GameLayer/GameLayer.h>
#include <vector>

namespace Lumina
{

void GameLayer::OnAttach()
{
    app = Application::Get();

    std::string vPth = "test_vert.glsl", fPth = "test_frag.glsl";
    testShader = RHIShader::Create(vPth, fPth);

    triangleMesh = new Mesh{vertices, indices, *testShader};
    testScene.meshes.push_back(triangleMesh);
    ENGINE_LOG(this->GetName() << " attached");
}

void GameLayer::OnDetach()
{
    app = nullptr;
    delete testShader;
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
                // ENGINE_LOG("event triggered: " << e.GetName() << " From: " <<
                // GetName()); ENGINE_LOG("Event key is: " << e.key);

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
