#include "Mesh.h"
#include "Core/Log.h"
#include "RHI/OpenGL/Shader/OpenGLShader.h"
#include "Scene/Vertex.h"

namespace Lumina
{

Mesh::Mesh(const std::vector<Vertex>& vertices, Shader& shader, int numInstances) :
    numInstances(numInstances), shader(&shader), vertices(vertices)
{
    usesIndices = false;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // float vertices_arr[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(),
        GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);
    glEnableVertexAttribArray(0);
}

Mesh::Mesh(const std::vector<Vertex>& vertices,
    const std::vector<unsigned int>& indices,
    Shader& shader,
    int numInstances) :
    numInstances(numInstances), shader(&shader), vertices(vertices), indices(indices)
{
    usesIndices = true;
}
Mesh::~Mesh() {}

} // namespace Lumina
