#include "OpenGLContext.h"
#include <Core/Log.h>
#include <glad/glad.h>
#include <stdexcept>

namespace Lumina
{

OpenGLContext::OpenGLContext(Window* windowHandle) : m_WindowHandle(windowHandle) {}

void OpenGLContext::Init()
{
    if (!gladLoadGLLoader((GLADloadproc) m_WindowHandle->GetProcAddress()))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback([](GLenum source, GLenum type, GLuint id, GLenum severity,
                               GLsizei length, const GLchar* message, const void*)
            { ENGINE_WARN("GL DEBUG: %s\n"
                          << message); },
        nullptr);

    ENGINE_LOG("Created OpenGL context");
}

RHIContext* RHIContext::Create(Window* windowHandle)
{
    return new OpenGLContext(windowHandle);
}

} // namespace Lumina
