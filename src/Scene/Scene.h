#pragma once
#include <Scene/Camera.h>
#include <Scene/Mesh.h>
#include <vector>

class Scene
{
  public:
    Scene();
    Camera camera;
    std::vector<Mesh> mesh;

  private:
};
