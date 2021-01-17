#ifndef PLANE_HPP
#define PLANE_HPP

#include "vector3.hpp"
#include "object.hpp"

class Plane : public Object {
 public:
  Plane();
  Plane(Vector3 center_, Vector3 normal_);

 private:
  Vector3 normal, center;
};


#endif //PLANE_HPP