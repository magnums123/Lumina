#pragma once
#include "RHI/OpenGL/Shader/OpenGLShader.h"
#include <Core/Window.h>
#include <RHI/Renderer.h>

namespace Lumina
{
class OpenGLRenderer : public RHIRenderer

{
  private:
    Window* windowHandle;
    Shader* shader = nullptr;
    unsigned int VAO, VBO;

  public:
    OpenGLRenderer(Window* windowHandle);

    void Init() override;
    void SubmitScene(const Scene& scene) override;
    void StartFrame() override;
    void EndFrame() override;
    void Destroy() override;
};
} // namespace Lumina
