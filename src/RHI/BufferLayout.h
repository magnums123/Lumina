#pragma once
#include <RHI/Shader.h>
#include <vector>

namespace Lumina
{

struct BufferElement
{
    ShaderDataType type;
    uint32_t size;
    size_t offset;
    bool normalized;

    BufferElement(ShaderDataType type, bool normalized = false) :
        type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized)
    {
    }
};

class BufferLayout
{
  public:
    BufferLayout(std::initializer_list<BufferElement> elements) : m_Elements(elements)
    {
        CalculateOffsetsAndStride();
    }

    const std::vector<BufferElement>& GetElements() const { return m_Elements; }
    uint32_t GetStride() const { return m_Stride; }

  private:
    void CalculateOffsetsAndStride()
    {
        size_t offset = 0;
        m_Stride = 0;
        for (auto& element : m_Elements)
            {
                element.offset = offset;
                offset += element.size;
                m_Stride += element.size;
            }
    }

    std::vector<BufferElement> m_Elements;
    uint32_t m_Stride = 0;
};
} // namespace Lumina
