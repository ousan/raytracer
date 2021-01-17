#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vector3.hpp"

class Light {
  public:
    virtual ~Light() = default;
    Vector3 position;
    Vector3 intensity;
    unsigned char type;

    int samples;
    float width, height;

    Light();
    Light(Vector3 _intensity);
    Light(Vector3 _position, Vector3 _intensity);
    virtual float attenuate(const float &r) const;
};

class AmbientLight : public Light {
  public:
    AmbientLight();
    AmbientLight(Vector3 _intensity);
    float attenuate(const float &r) const;
};

class AreaLight : public Light {
  public:
    AreaLight();
    AreaLight(Vector3 _position, Vector3 _intensity);
    float attenuate(const float &r) const;
};

#endif //LIGHT_HPP