#include "Core/Log.h"
#include "RHI/OpenGL/Shader/OpenGLShader.h"
#include <Core/Window.h>
#include <RHI/Context.h>
#include <RHI/OpenGL/Renderer/OpenGLRenderer.h>

namespace Lumina
{
OpenGLRenderer::OpenGLRenderer(Window* windowHandle)
{
    context = RHIContext::Create(windowHandle);
    ENGINE_LOG("Created Uninitialized Context");
}

void OpenGLRenderer::Init()
{
    context->Init();
    ENGINE_LOG("Context Initialized");
}

void OpenGLRenderer::SubmitScene(const Scene& scene)
{
    StartFrame();
    for (const Mesh& mesh : scene.meshes)
        {
            if (mesh.numInstances > 1)
                {
                    DrawMeshInstanced(mesh);
                }
            else
                {
                    DrawMesh(mesh);
                }
        }
    EndFrame();
}

void OpenGLRenderer::DrawMesh(const Mesh& mesh)
{
    if (mesh.usesIndices)
        {
            // Use IBO
        }
    else
        {
            mesh.shader->use();
            glBindVertexArray(mesh.VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
}

void OpenGLRenderer::DrawMeshInstanced(const Mesh& mesh)
{
    if (mesh.usesIndices)
        {
            // Use IBO
        }
    else
        {
            // Normal Rendering
        }
}

void OpenGLRenderer::StartFrame()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::EndFrame() {}

void OpenGLRenderer::Destroy() {}

RHIRenderer* RHIRenderer::Create(Window* windowHandle)
{
    return new OpenGLRenderer(windowHandle);
}
} // namespace Lumina
