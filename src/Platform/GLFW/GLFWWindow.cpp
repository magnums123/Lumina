#include "GLFWWindow.h"
#include "Core/Log.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace Lumina
{

static bool s_GLFWInitialized = false;

Window* Window::Create(const WindowProps& props) { return new GLFWWindow(props); }

GLFWWindow::GLFWWindow(const WindowProps& props) { Init(props); }

GLFWWindow::~GLFWWindow() { Shutdown(); }

void GLFWWindow::Init(const WindowProps& props)
{
    m_Data.Title = props.Title;
    m_Data.Width = props.Width;
    m_Data.Height = props.Height;

    if (!s_GLFWInitialized)
        {
            if (!glfwInit())
                throw std::runtime_error("Failed to initialize GLFW");

            s_GLFWInitialized = true;
        }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(
        (int) props.Width, (int) props.Height, m_Data.Title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, &m_Data);
    glfwSwapInterval(1);

    glfwSetWindowCloseCallback(m_Window,
        [](GLFWwindow* window)
            {
                WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
                WindowCloseEvent event;
                data.EventCallback(event);
            });
    ENGINE_LOG("Created GLFW Window");
}

void GLFWWindow::Shutdown() { glfwDestroyWindow(m_Window); }

void GLFWWindow::OnUpdate() { glfwPollEvents(); }

void GLFWWindow::SwapBuffers() { glfwSwapBuffers(m_Window); }

void* GLFWWindow::GetProcAddress() { return (void*) glfwGetProcAddress; }

} // namespace Lumina
