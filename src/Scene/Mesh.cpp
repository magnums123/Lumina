#include "Mesh.h"
#include "RHI/Buffer.h"
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

    const auto& layout = Vertex::GetLayout();
    uint32_t index = 0;

    for (const auto& element : layout.GetElements())
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.size / 4, GL_FLOAT,
                element.normalized ? GL_TRUE : GL_FALSE, layout.GetStride(),
                (const void*) element.offset);
            index++;
        }
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

    const auto& layout = Vertex::GetLayout();
    uint32_t index = 0;

    for (const auto& element : layout.GetElements())
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.size / 4, GL_FLOAT,
                element.normalized ? GL_TRUE : GL_FALSE, layout.GetStride(),
                (const void*) element.offset);
            index++;
        }
}
Mesh::~Mesh()
{
    delete vertexArrayBuffer;
    delete vertexBuffer;
    if (usesIndices)
        delete indexBuffer;
}

} // namespace Lumina
