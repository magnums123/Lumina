#include <Core/Window.h>
#include <RHI/Context.h>
#include <RHI/OpenGL/Renderer/OpenGLRenderer.h>

namespace Lumina
{
OpenGLRenderer::OpenGLRenderer(Window* windowHandle) : windowHandle(windowHandle)
{
    context = RHIContext::Create(windowHandle);
}

void OpenGLRenderer::Init() { context->Init(); }

void OpenGLRenderer::SubmitScene(const Scene& scene)
{
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
}

void OpenGLRenderer::DrawMesh(const Mesh& mesh)
{
    if (mesh.usesIndices)
        {
            // Use IBO
        }
    else
        {
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);

            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);

            glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size(), mesh.vertices.data(),
                GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
            glEnableVertexAttribArray(0);
            // Normal Rendering
            mesh.shader->use();
            glBindVertexArray(VAO);
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

void OpenGLRenderer::Destroy()
{
    // shader->Delete();
    // delete shader;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

RHIRenderer* RHIRenderer::Create(Window* windowHandle)
{
    return new OpenGLRenderer(windowHandle);
}
} // namespace Lumina
