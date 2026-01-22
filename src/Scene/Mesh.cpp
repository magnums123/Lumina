#include "Mesh.h"

namespace Lumina
{

Mesh::Mesh(const std::vector<Vertex>& vertices, Shader* shader, int numInstances) :
    numInstances(numInstances), shader(shader), vertices(vertices)
{
    usesIndices = false;
}

Mesh::Mesh(const std::vector<Vertex>& vertices,
    const std::vector<unsigned int>& indices,
    Shader* shader,
    int numInstances) :
    numInstances(numInstances), shader(shader), vertices(vertices), indices(indices)
{
    usesIndices = true;
}

} // namespace Lumina
