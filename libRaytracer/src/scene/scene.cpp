#include "scene.hpp"

Scene::Scene() 
{ 
    backgroundColor = Color(); 
}

void Scene::addAmbientLight(AmbientLight _light) 
{ 
    ambientLight = _light;
}

void Scene::addLight(Light *_light) 
{ 
    lights.push_back(_light); 
}

void Scene::addObject(Object *_object) 
{ 
    objects.push_back(_object); 
}