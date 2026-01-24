#include "Mesh.h"
#include <Scene/Vertex.h>
#include <glad/glad.h>

namespace Lumina
{

Mesh::Mesh(const std::vector<Vertex>& vertices, RHIShader& shader, int numInstances) :
    numInstances(numInstances), shader(&shader), vertices(vertices)
{
    usesIndices = false;

    vertexArrayBuffer->Bind();
    vertexBuffer->Bind();

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(),
        GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);

    glEnableVertexAttribArray(0);
}

Mesh::Mesh(const std::vector<Vertex>& vertices,
    const std::vector<unsigned int>& indices,
    RHIShader& shader,
    int numInstances) :
    numInstances(numInstances), shader(&shader), vertices(vertices), indices(indices)
{
    usesIndices = true;

    vertexArrayBuffer->Bind();

    vertexBuffer->Bind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(),
        GL_STATIC_DRAW);

    indexBuffer->Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);

    glEnableVertexAttribArray(0);
}
Mesh::~Mesh()
{
    delete vertexArrayBuffer;
    delete vertexBuffer;
    delete indexBuffer;
}

} // namespace Lumina
