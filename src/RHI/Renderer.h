#pragma once
#include <Core/Window.h>
#include <RHI/Context.h>
#include <Scene/Scene.h>

namespace Lumina
{
class RHIRenderer
{
  protected:
    RHIContext* context;

    virtual void StartFrame() = 0;
    virtual void EndFrame() = 0;

  public:
    RHIRenderer() = default;
    virtual ~RHIRenderer() = default;

    virtual void Init() = 0;
    virtual void SubmitScene(const Scene& scene) = 0;
    virtual void DrawMesh(const Mesh& mesh) = 0;
    // TODO: Take in the transforms for each instance as a parameter (Array or Vector)
    virtual void DrawMeshInstanced(const Mesh& mesh) = 0;
    virtual void Destroy() = 0;

    static RHIRenderer* Create(Window* windowHandle);
};
} // namespace Lumina
