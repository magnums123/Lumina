#pragma once
#include <Scene/Camera.h>
#include <Scene/Mesh.h>
#include <vector>

namespace Lumina
{
class Scene
{
  public:
    Scene(Camera& camera) : camera(camera) {};
    Camera camera;
    std::vector<Mesh*> meshes;
};
} // namespace Lumina
