#ifndef LIGHTING_HPP
#define LIGHTING_HPP

#include "color.hpp"
#include "vector3.hpp"
#include "light.hpp"
#include "object.hpp"

#include <vector>

class Lighting { 
  public:

    static Color getLighting(const Object &object, 
                      const Vector3 &point, 
                      const Vector3 &normal, 
                      const Vector3 &view, 
                      const vector<Light*> &lights, 
                      const vector<Object*> &objects);

    static bool getShadow(const Vector3 &point, 
                   const Light &light, 
                   const vector<Object*> &objects);

    static float getShadowFactor(const Vector3 &point, 
                          const Light &light, 
                          const vector<Object*> &objects);

    static Color getLighting(const Object &object, 
                      const Vector3 &point, 
                      const Vector3 &normal, 
                      const Vector3 &view, 
                      const Light *light);
};

#endif //LIGHTING_HPP