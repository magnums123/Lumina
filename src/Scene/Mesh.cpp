#include <RHI/Renderer.h>
#include <Scene/Mesh.h>

namespace Lumina
{

Mesh::Mesh(const std::vector<Vertex>& vertices, Shader* shader) :
    shader(shader), m_Vertices(vertices)
{
    usesIndices = false;
}

Mesh::Mesh(const std::vector<Vertex>& vertices,
    const std::vector<unsigned int>& indices,
    Shader* shader) : shader(shader), m_Vertices(vertices), m_Indices(indices)
{
    usesIndices = true;
}

void Mesh::Draw(RHIRenderer* renderer) const { renderer->DrawMesh(this); }
} // namespace Lumina
