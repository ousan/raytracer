
#include "sphere.hpp"

Sphere::Sphere(const Vector3 &_center, 
               const float _radius, 
               const Color &_color, 
               const float _ka, 
               const float _kd, 
               const float _ks, 
               const float _shinny , 
               const float _reflectScale , 
               const float _transparency ) 
:radius(_radius), radius2(_radius*_radius)
{ 
    center = _center;
    color = _color;
    color_specular = Color(255);
    ka = _ka;
    kd = _kd;
    ks = _ks;
    shininess = _shinny;
    reflectivity = _reflectScale;
    transparency = _transparency;
    glossiness = 0;
    glossy_transparency = 0;
}

// Compute a ray-sphere intersection using the geometric method
bool Sphere::intersect(const Ray &ray, float &t0, float &t1) {
    Vector3 l = center - ray.origin;
    float tca = l.dot(ray.direction); // Closest approach
    if (tca < 0) return false; // Ray intersection behind ray origin
    float d2 = l.dot(l) - tca*tca;
    if (d2 > radius2) return false; // Ray doesn't intersect
    float thc = sqrt(radius2 - d2); // Closest approach to surface of sphere
    t0 = tca - thc;
    t1 = tca + thc;
    return true;
}

// Computer a ray-sphere intersection using analytic method (w/ quadratic equation)
bool Sphere::intersect2(const Ray &ray, float &t) {
    Vector3 o = ray.origin;
    Vector3 d = ray.direction;
    Vector3 oc = o - center;
    float b = 2 * oc.dot(d);
    float c = oc.dot(oc) - radius2;
    float disc = b*b - 4*c;
    if(disc < 0) return false;
    else {
    disc = sqrt(disc);
    float t0 = -b - disc;
    float t1 = -b + disc;
    t = (t0 < t1) ? t0 : t1;
    return true;
    }
}

Vector3 Sphere::getNormal(const Vector3 &hitPoint) {
    return (hitPoint - center) / radius;
}