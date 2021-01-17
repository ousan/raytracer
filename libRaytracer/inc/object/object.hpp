#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "vector3.hpp"
#include "color.hpp"
#include "ray.hpp"

class Object {
  public:
    virtual ~Object() = default;
    
    Vector3 center;           // Position
    Color color;              // Surface Diffuse Color
    Color color_specular;     // Surface Specular Color
    float ka, kd, ks;         // Ambient, Diffuse, Specular Coefficents
    float shininess;
    float reflectivity;       // Reflectivity of material [0, 1]
    float transparency;       // Transparency of material [0, 1]
    float glossiness;         // Strength of glossy reflections
    float glossy_transparency; // Strength of glossy transparency

    virtual bool intersect(const Ray &ray, float &to, float &t1);
    virtual Vector3 getNormal(const Vector3 &hitPoint);
};

#endif //OBJECT_HPP