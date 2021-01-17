#ifndef SCENE_HPP
#define SCENE_HPP

#include "light.hpp"
#include "object.hpp"

#include <vector>

class Scene {
  public:
    vector<Object*> objects;
    vector<Light*> lights;
    AmbientLight ambientLight;
    Color backgroundColor;

    Scene();
    void addAmbientLight(AmbientLight _light);
    void addLight(Light *_light);
    void addObject(Object *_object);
};

#endif //SCENE_HPP