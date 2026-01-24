#pragma once

#include <cstddef>
#include <vector>
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
  public:
    RHIBuffer(BufferType bufferType) : bufferType(bufferType) {};
    virtual ~RHIBuffer() = default;

    BufferType bufferType;

    virtual void Bind() = 0;
    virtual void UnBind() = 0;

    virtual void Delete() = 0;
    virtual void SetData(const void* data, size_t size) = 0;

    static RHIBuffer* Create(BufferType bufferType);

    template <typename T>
    static void SetupData(RHIBuffer* buffer, std::vector<T> data)
    {
        buffer->SetData(data.data(), data.size() * sizeof(T));
    };
};

} // namespace Lumina
