#include "raytracer.hpp"

Raytracer::~Raytracer()
{

}


Raytracer::Raytracer()
{

}

Raytracer::Raytracer(Scene _scene, Camera _camera, Canvas _canvas)
: scene(_scene), camera(_camera), canvas(_canvas)
{

}

void Raytracer::setCanvasSize(int width,int height)
{
    canvas.setCanvasSize(height,width);
}

void Raytracer::setCameraPosition(Vector3 location, float field_of_view)
{
    camera = Camera(location,canvas.getCanvasWidth(), canvas.getCanvasHeight(),field_of_view);
}

void Raytracer::addSceneLight(Vector3 location, Vector3 intensity)
{
    AreaLight *l; 
    l = new AreaLight(location,intensity);
    scene.addLight(l);
    scene.addAmbientLight ( AmbientLight( Vector3(1.0) ) );
}

void Raytracer::addTriangle(Vector3 a,Vector3 b,Vector3 c, Color color)
{
    Triangle *t;
    t = new Triangle(a,b,c,color);
    scene.addObject(t);
}

void Raytracer::addSphere(Vector3 location, int radius, Color color)
{
    Sphere *s ;
    s = new Sphere(location,radius,color);
    scene.addObject(s);
}

void Raytracer::renderScene()
{
    Renderer r = Renderer(canvas.getCanvasWidth(), canvas.getCanvasHeight(), scene, camera); 
    r.render();
}

void Raytracer::addPlane(Vector3 location,Vector3 normal, Color color)
{
    
}
