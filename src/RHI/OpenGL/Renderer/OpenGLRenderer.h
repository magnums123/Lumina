#pragma once
#include <Core/Window.h>
#include <RHI/Renderer.h>

namespace Lumina
{
class OpenGLRenderer : public RHIRenderer

{
  private:
    Window* windowHandle;
    unsigned int VAO, VBO;

  public:
    OpenGLRenderer(Window* windowHandle);

    void Init() override;
    void SubmitScene(const Scene& scene) override;
    void DrawMesh(const Mesh& mesh) override;
    void DrawMeshInstanced(const Mesh& mesh) override;
    void StartFrame() override;
    void EndFrame() override;
    void Destroy() override;
};
} // namespace Lumina
