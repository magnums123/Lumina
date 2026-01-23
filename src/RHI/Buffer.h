#pragma once

namespace Lumina
{

enum class BufferType
{
    None = 0,
    VertexArray,
    VertexBuffer,
    IndexBuffer
};

class RHIBuffer
{
  protected:
    BufferType bufferType;

  public:
    RHIBuffer(BufferType bufferType) : bufferType(bufferType) {};
    virtual ~RHIBuffer() = default;

    virtual void Bind() = 0;
    virtual void UnBind() = 0;
    virtual void Delete() = 0;

    static RHIBuffer* Create(BufferType bufferType);
};
} // namespace Lumina
