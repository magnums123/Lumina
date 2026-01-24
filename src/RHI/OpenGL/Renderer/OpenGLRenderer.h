#pragma once
#include <Core/Window.h>
#include <RHI/Renderer.h>

namespace Lumina
{
class OpenGLRenderer : public RHIRenderer

{
  private:
    void StartFrame() override;
    void EndFrame() override;

  public:
    OpenGLRenderer(Window* windowHandle);

    void Init() override;
    void SubmitScene(const Scene& scene) override;
    void DrawMesh(const Mesh* mesh) override;
    void DrawMeshInstanced(const Mesh* mesh) override;
    void Destroy() override;
};
} // namespace Lumina
