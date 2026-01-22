#include "OpenGLContext.h"
#include <Core/Log.h>
#include <glad/glad.h>
#include <stdexcept>

namespace Engine
{

OpenGLContext::OpenGLContext(Window* windowHandle) : m_WindowHandle(windowHandle) {}

void OpenGLContext::Init()
{
    if (!gladLoadGLLoader((GLADloadproc) m_WindowHandle->GetProcAddress()))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }
    ENGINE_LOG("Created OpenGL context");
}

RHIContext* RHIContext::Create(Window* windowHandle)
{
    return new OpenGLContext(windowHandle);
}

} // namespace Engine
