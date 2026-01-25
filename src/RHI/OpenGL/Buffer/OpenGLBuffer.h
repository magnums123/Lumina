#pragma once
#include <RHI/Buffer.h>

namespace Lumina
{

class OpenGLBuffer : public RHIBuffer
{
  private:
    unsigned int ID = 0;

    void SetupVertexAttribute();

  public:
    OpenGLBuffer(BufferType bufferType);
    ~OpenGLBuffer() override;

    void Bind() override;
    void SetData(const void* data, size_t size) override;
    void UnBind() override;

    void Delete() override;
};
} // namespace Lumina
