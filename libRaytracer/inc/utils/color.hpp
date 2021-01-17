#ifndef COLOR_HPP
#define COLOR_HPP

#include "vector3.hpp"

struct Color {
  float r, g, b;
  Color();
  Color(float c);
  Color(float _r, float _g, float _b);
  Color operator * (float f) const;
  Color operator * (Vector3 f) const;
  Color operator * (Color c) const;
  Color operator + (Color c) const;
  Color& operator += (const Color &c);
  Color& operator *= (const Color &c);

  Color& clamp();
};

#endif //COLOR_HPP