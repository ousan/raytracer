#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "vector3.hpp"
#include "color.hpp"
#include "object.hpp"

#define K_EPSILON 0.00001

class Triangle : public Object {
  public:
    Vector3 v0;
    Vector3 v1;
    Vector3 v2;
    Triangle(const Vector3 &_v0, 
            const Vector3 &_v1, 
            const Vector3 &_v2, 
            const Color &_color, 
            const float _ka = 1.0, 
            const float _kd = 0.5, 
            const float _ks = 0.0, 
            const float _shinny = 128.0, 
            const float _reflectScale = 1.0, 
            const float _transparency = 0.0);
    
    // Compute a ray-triangle intersection
    bool intersect(const Ray &ray, float &t, float &tnone);

    Vector3 getNormal(const Vector3 &hitPoint);
};

#endif //TRIANGLE_HPP