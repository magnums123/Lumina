#pragma once
#include <string>
namespace Lumina

{

enum class ShaderDataType
{
    Float,
    Float2,
    Float3,
    Float4,
    Int,
    Int2,
    Int3,
    Int4
};

static uint32_t ShaderDataTypeSize(ShaderDataType type)
{
    switch (type)
        {
            case ShaderDataType::Float:
                return 4;
            case ShaderDataType::Float2:
                return 8;
            case ShaderDataType::Float3:
                return 12;
            case ShaderDataType::Float4:
                return 16;
            case ShaderDataType::Int:
                return 4;
            case ShaderDataType::Int2:
                return 8;
            case ShaderDataType::Int3:
                return 12;
            case ShaderDataType::Int4:
                return 16;
        }
    return 0;
}

class RHIShader
{

  public:
    virtual ~RHIShader() = default;

    virtual void Use() = 0;
    virtual void SetUniforms() = 0;
    virtual void Delete() = 0;

    static RHIShader* Create(
        std::string& vertexShaderPath, std::string& fragmentShaderPath);

  protected:
    bool isValid = false;
    virtual void Load(std::string& vertexShaderPath, std::string& fragmentShaderPath) = 0;
};

} // namespace Lumina
