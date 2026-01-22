#pragma once
#include "RHI/OpenGL/Shader/OpenGLShader.h"
#include <Core/Window.h>
#include <RHI/Renderer.h>

namespace Engine
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
    void SubmitScene(Scene& scene) override;
    void StartFrame() override;
    void EndFrame() override;
    void Destroy() override;
};
} // namespace Engine
