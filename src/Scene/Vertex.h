#pragma once
#include <RHI/BufferLayout.h>
#include <RHI/Shader.h>
#include <glm/vec3.hpp>

namespace Lumina
{

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Color;

    static BufferLayout GetLayout()
    {
        return {
            {ShaderDataType::Float3}, // Position
            {ShaderDataType::Float3}, // Color //Temp
            // {ShaderDataType::Float3}, // Normal
            // {ShaderDataType::Float2}  // UV
        };
    }
};

} // namespace Lumina
