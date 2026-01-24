#pragma once
#include "RHI/Shader.h"
#include <glad/glad.h> // include glad to get the required OpenGL headers
#include <string>
namespace Lumina
{
class OpenGLShader : public RHIShader
{
  private:
    void Load(std::string& vertexShaderPath, std::string& fragmentShaderPath) override;

  public:
    unsigned int ID = 0;

    OpenGLShader(std::string& vertexShaderPath, std::string& fragmentShaderPath)
    {
        Load(vertexShaderPath, fragmentShaderPath);
    }
    ~OpenGLShader() override;

    void Use() override;
    void SetUniforms() override;
    void Delete() override;

    // utility uniform functions
    // void setBool(const std::string& name, bool value) const;
    // void setInt(const std::string& name, int value) const;
    // void setFloat(const std::string& name, float value) const;
};
}; // namespace Lumina
