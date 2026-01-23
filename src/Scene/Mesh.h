#pragma once
#include "RHI/OpenGL/Shader/OpenGLShader.h"
#include <RHI/Buffer.h>
#include <Scene/Vertex.h>
#include <vector>

namespace Lumina
{
struct Mesh
{
  public:
    Mesh(const std::vector<Vertex>& vertices, Shader& shader, int numInstances = -1);
    Mesh(const std::vector<Vertex>& vertices,
        const std::vector<unsigned int>& indices,
        Shader& shader,
        int numInstances = -1);
    ~Mesh();

    bool usesIndices = false;
    int numInstances = -1;

    Shader* shader;

    RHIBuffer* vertexArrayBuffer = RHIBuffer::Create(BufferType::VertexArray);
    RHIBuffer* vertexBuffer = RHIBuffer::Create(BufferType::VertexBuffer);
    RHIBuffer* indexBuffer = RHIBuffer::Create(BufferType::IndexBuffer);

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};
} // namespace Lumina
