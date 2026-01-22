#pragma once
#include "RHI/OpenGL/Shader/OpenGLShader.h"
#include <Scene/Vertex.h>
#include <vector>
namespace Lumina
{
class Mesh
{
  public:
    Mesh(const std::vector<Vertex>& vertices, Shader* shader);
    Mesh(const std::vector<Vertex>& vertices,
        const std::vector<unsigned int>& indices,
        Shader* shader);

    bool usesIndices = false;

  private:
    Shader* shader;
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;

    virtual void Draw();
};
} // namespace Lumina
