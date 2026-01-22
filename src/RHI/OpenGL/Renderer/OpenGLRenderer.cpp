#include <Core/Window.h>
#include <RHI/Context.h>
#include <RHI/OpenGL/Renderer/OpenGLRenderer.h>
#include <Scene/Mesh.h>

float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

namespace Lumina
{
OpenGLRenderer::OpenGLRenderer(Window* windowHandle) : windowHandle(windowHandle)
{
    context = RHIContext::Create(windowHandle);
}

void OpenGLRenderer::Init()
{
    context->Init();
    shader = new Shader("test_vert.glsl", "test_frag.glsl");
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
}

void OpenGLRenderer::SubmitScene(const Scene& scene)
{
    for (const Mesh& mesh : scene.meshes)
        {
            mesh.Draw(this);
        }
}

void OpenGLRenderer::StartFrame()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::EndFrame()
{
    shader->use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLRenderer::Destroy()
{
    shader->Delete();
    delete shader;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

RHIRenderer* RHIRenderer::Create(Window* windowHandle)
{
    return new OpenGLRenderer(windowHandle);
}
} // namespace Lumina
