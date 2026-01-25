#include "Mesh.h"
#include <RHI/Buffer.h>
#include <Scene/Vertex.h>
#include <glad/glad.h>

namespace Lumina
{

Mesh::Mesh(const std::vector<Vertex>& vertices, RHIShader& shader, int numInstances) :
    numInstances(numInstances), shader(&shader), vertices(vertices)
{
    vertexArrayBuffer = RHIBuffer::Create(BufferType::VertexArray);
    vertexBuffer = RHIBuffer::Create(BufferType::VertexBuffer);

    usesIndices = false;

    vertexArrayBuffer->Bind();
    vertexBuffer->Bind();
    RHIBuffer::SetupData(vertexBuffer, vertices);
}

Mesh::Mesh(const std::vector<Vertex>& vertices,
    const std::vector<unsigned int>& indices,
    RHIShader& shader,
    int numInstances) :
    numInstances(numInstances), shader(&shader), vertices(vertices), indices(indices)
{
    vertexArrayBuffer = RHIBuffer::Create(BufferType::VertexArray);
    vertexBuffer = RHIBuffer::Create(BufferType::VertexBuffer);
    indexBuffer = RHIBuffer::Create(BufferType::IndexBuffer);

    usesIndices = true;

    vertexArrayBuffer->Bind();

    vertexBuffer->Bind();
    RHIBuffer::SetupData(vertexBuffer, vertices);

    indexBuffer->Bind();
    RHIBuffer::SetupData<unsigned int>(indexBuffer, indices);
}
Mesh::~Mesh()
{
    delete vertexArrayBuffer;
    delete vertexBuffer;
    if (usesIndices)
        delete indexBuffer;
}

} // namespace Lumina
