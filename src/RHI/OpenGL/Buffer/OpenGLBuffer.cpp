#include "OpenGLBuffer.h"
#include "Core/Log.h"
#include "RHI/Buffer.h"
#include "Scene/Vertex.h"
#include <glad/glad.h>

namespace Lumina
{

OpenGLBuffer::OpenGLBuffer(BufferType bufferType) : RHIBuffer(bufferType)
{
    switch (bufferType)
        {
            case BufferType::VertexArray:
                glGenVertexArrays(1, &ID);
                break;
            case BufferType::VertexBuffer:
                glGenBuffers(1, &ID);
                break;
            case BufferType::IndexBuffer:
                glGenBuffers(1, &ID);
                break;
            default:
                ENGINE_WARN("Invalid BufferType Created.");
                break;
        }
    ENGINE_LOG("Created New Buffer");
}

OpenGLBuffer::~OpenGLBuffer() { Delete(); }

void OpenGLBuffer::Bind()
{

    switch (bufferType)
        {
            case BufferType::VertexArray:
                glBindVertexArray(ID);
                break;
            case BufferType::VertexBuffer:
                glBindBuffer(GL_ARRAY_BUFFER, ID);
                break;
            case BufferType::IndexBuffer:
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
                break;
            default:
                break;
        }
}

void OpenGLBuffer::UnBind()
{

    switch (bufferType)
        {
            case BufferType::VertexArray:
                glBindVertexArray(0);
                break;
            case BufferType::VertexBuffer:
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                break;
            case BufferType::IndexBuffer:
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                break;
            default:
                break;
        }
}

void OpenGLBuffer::SetData(const void* data, size_t size)
{

    switch (bufferType)
        {
            case BufferType::VertexBuffer:
                glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
                break;
            case BufferType::IndexBuffer:
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
                break;
            default:
                break;
        }
}

void OpenGLBuffer::Delete()
{

    switch (bufferType)
        {
            case BufferType::VertexArray:
                glDeleteVertexArrays(1, &ID);
                break;
            case BufferType::VertexBuffer:
                glDeleteBuffers(1, &ID);
                break;
            case BufferType::IndexBuffer:
                glDeleteBuffers(1, &ID);
                break;
            default:
                break;
        }
}

RHIBuffer* RHIBuffer::Create(BufferType bufferType)
{
    return new OpenGLBuffer(bufferType);
}
} // namespace Lumina
