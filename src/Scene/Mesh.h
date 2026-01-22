#pragma once
#include <Scene/Vertex.h>
#include <vector>

class Mesh
{
  public:
    Mesh(std::vector<Vertex>& vertices);
    Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices);

    bool usesIndices = false;

  private:
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;

    virtual void Draw();
};
