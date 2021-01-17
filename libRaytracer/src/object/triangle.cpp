#include "triangle.hpp"

Triangle::Triangle(const Vector3 &_v0, 
                   const Vector3 &_v1, 
                   const Vector3 &_v2, 
                   const Color &_color, 
                   const float _ka, 
                   const float _kd, 
                   const float _ks, 
                   const float _shinny, 
                   const float _reflectScale , 
                   const float _transparency ) 
:v0(_v0), v1(_v1), v2(_v2)
{
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

// Compute a ray-triangle intersection
bool Triangle::intersect(const Ray &ray, float &t, float &tnone) 
{
    Vector3 N = getNormal(Vector3());

    // Check if ray and plane are parallel
    float NdotRd = N.dot(ray.direction);
    if(fabs(NdotRd) < K_EPSILON) {
    return false; // Ray and plane are parallel
    }
    
    // Compute d from the equation of a plane - ax + by + cz + d = 0, n = (a,b,c)
    float d = N.dot(v0);

    // Compute t
    float NdotRo = N.dot(ray.origin);
    t = - ((NdotRo + d) / NdotRd);
    if(t < 0) return false; // Triangle is behind ray

    // Compute intersection point with plane
    Vector3 hitPoint = ray.origin + ray.direction * t;

    // Check if intersection point is inside triangle
    Vector3 C; 

    Vector3 v01 = v1 - v0;
    Vector3 v12 = v2 - v1;
    Vector3 v20 = v0 - v2;
    
    Vector3 vp0 = hitPoint - v0;
    C = v01.cross(vp0);
    if (N.dot(C) < 0) return false;

    Vector3 vp1 = hitPoint - v1;
    C = v12.cross(vp1);
    if (N.dot(C) < 0) return false;

    Vector3 vp2 = hitPoint - v2;
    C = v20.cross(vp2);
    if (N.dot(C) < 0) return false;
    
    return true; // Triangle intersects ray
}

Vector3 Triangle::getNormal(const Vector3 &hitPoint) {
    Vector3 v01 = v1 - v0;
    Vector3 v02 = v2 - v0;
    Vector3 N = v01.cross(v02);
    N.normalize(); 
    return N;
}