#ifndef RAY_HPP
#define RAY_HPP

#include "vector3.hpp"

class Ray {
  public:
    Vector3 origin;
    Vector3 direction;
    Ray(Vector3 _origin, Vector3 _direction);
};

#endif //RAY_HPP