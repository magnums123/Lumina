#pragma once
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/vector_float3.hpp"
#include <glm/glm.hpp>

namespace Lumina
{
class Camera
{
  public:
    Camera(float fov, int width, int height) : fov(fov), width(width), height(height) {};

  private:
    int width, height;
    float pitch, yaw, fov;

    glm::vec3 Position;
    glm::vec3 Up;
    glm::vec3 Right;

    glm::mat4 Projection{1.f};
    glm::mat4 view{1.f};
};
} // namespace Lumina
