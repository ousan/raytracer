#include "light.hpp"

Light::Light() 
: position(Vector3()), intensity(Vector3()) 
{ 
    type = 0x01; 
}

Light::Light(Vector3 _intensity) 
: position(Vector3()), intensity(_intensity) 
{ 
    type = 0x01; 
}

Light::Light(Vector3 _position, Vector3 _intensity) 
: position(_position), intensity(_intensity) 
{ 
    type = 0x01; 
}

float Light::attenuate(const float &r) const 
{ 
    return 1.0; 
}

AmbientLight::AmbientLight() 
: Light() 
{ 
    type = 0x02; 
}

AmbientLight::AmbientLight(Vector3 _intensity) 
: Light(_intensity) 
{ 
    type = 0x02; 
}

float AmbientLight::attenuate(const float &r) const 
{ 
    return 1.0;
}

AreaLight::AreaLight() 
: Light() 
{
    type = 0x20;
    samples = 2;
    width = 4;
    height = 4;
}

AreaLight::AreaLight(Vector3 _position, Vector3 _intensity) 
: Light(_position, _intensity) 
{
    type = 0x20;
    samples = 2;
    width = 4;
    height = 4;
}

float AreaLight::attenuate(const float &r) const 
{ 
    return 1.0; 
}