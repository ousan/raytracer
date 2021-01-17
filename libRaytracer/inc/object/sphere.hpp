#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vector3.hpp"
#include "color.hpp"
#include "object.hpp"

class Sphere : public Object {
  public:
    float radius, radius2;

    Sphere(const Vector3 &_center, 
           const float _radius, 
           const Color &_color, 
           const float _ka = 0.3, 
           const float _kd = 0.8, 
           const float _ks = 0.5, 
           const float _shinny = 128.0, 
           const float _reflectScale = 1.0, 
           const float _transparency = 0.0);
    
    // Compute a ray-sphere intersection using the geometric method
    bool intersect(const Ray &ray, float &t0, float &t1);

    // Computer a ray-sphere intersection using analytic method (w/ quadratic equation)
    bool intersect2(const Ray &ray, float &t);

    Vector3 getNormal(const Vector3 &hitPoint);
};

#endif //SPHERE_HPP