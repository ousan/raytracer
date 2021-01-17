#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "vector3.hpp"

class Camera { 
  public:
    Vector3 position;
    int width, height;
    float invWidth, invHeight;
    float fov, aspectratio, angle;
    float angleX, angleY, angleZ;

    Camera(Vector3 _position, int _width, int _height, float _fov);
    Camera();
    Vector3 pixelToViewport(Vector3 pixel);
};

#endif //CAMERA_HPP