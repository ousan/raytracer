#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
#include <math.h>

using namespace std;

class Vector3 {
  public:
    float x, y, z;

    Vector3();
    Vector3(float xx);
    Vector3(float xx, float yy, float zz);

    Vector3 operator - () const;
    Vector3 operator + (const float &f) const;
    Vector3 operator - (const float &f) const;
    Vector3 operator * (const float &f) const;
    Vector3 operator / (const float &f) const;
    Vector3 operator + (const Vector3 &v) const;
    Vector3 operator - (const Vector3 &v) const;
    Vector3 operator * (const Vector3 &v)  const;
    Vector3& operator += (const Vector3 &v);
    Vector3& operator *= (const Vector3 &v);

    float dot(const Vector3 &v) const;
    Vector3 cross(const Vector3 &v) const;
    float length2() const;
    float length() const;

    Vector3& normalize();
    Vector3& rotateX(const float &angle);
    Vector3& rotateY(const float &angle);
    Vector3& rotateZ(const float &angle);
    static Vector3 random();
    friend ostream& operator << (ostream &os, const Vector3 &v) ;
};


#endif //VECTOR3_HPP