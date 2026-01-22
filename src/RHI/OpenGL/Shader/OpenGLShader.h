#pragma once
#include <glad/glad.h> // include glad to get the required OpenGL headers
#include <string>
namespace Lumina
{
class Shader
{
  public:
    // the program ID
    unsigned int ID = 0;
    bool isValid = false;
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    void Delete();
    // utility uniform functions
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
};
}; // namespace Lumina
