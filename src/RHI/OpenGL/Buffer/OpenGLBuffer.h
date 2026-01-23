#pragma once
#include <RHI/Buffer.h>

namespace Lumina
{

class OpenGLBuffer : public RHIBuffer
{
    unsigned int ID = -1;

  public:
    OpenGLBuffer(BufferType bufferType);
    ~OpenGLBuffer() override;

    void Bind() override;
    void UnBind() override;
    void Delete() override;
};
} // namespace Lumina
