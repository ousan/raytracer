#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "color.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "lighting.hpp"

#include <fstream>

#define MAX_RAY_DEPTH 5

class Renderer {
  public:
    int width, height;
    Scene scene;
    Camera camera;
    
    Renderer(float _width, float _height, Scene _scene, Camera _camera);

    void render();

    void render_distributed_rays();

    Color trace(const Ray &ray, const int &depth);

    void drawImage(Color* image, int width, int height);   
};

#endif //RENDERER_HPP