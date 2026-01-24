#pragma once

#include <string>
namespace Lumina
{

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
