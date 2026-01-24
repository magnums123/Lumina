#pragma once
#include <RHI/Buffer.h>
#include <RHI/Shader.h>
#include <Scene/Vertex.h>
#include <vector>

namespace Lumina
{
class Mesh
{
  public:
    Mesh(const std::vector<Vertex>& vertices, RHIShader& shader, int numInstances = -1);
    Mesh(const std::vector<Vertex>& vertices,
        const std::vector<unsigned int>& indices,
        RHIShader& shader,
        int numInstances = -1);
    ~Mesh();

    bool usesIndices = false;
    int numInstances = -1;

    RHIShader* shader;

    RHIBuffer* vertexArrayBuffer;
    RHIBuffer* vertexBuffer;
    RHIBuffer* indexBuffer;

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};
} // namespace Lumina
