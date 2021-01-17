#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include "vector3.hpp"
#include "color.hpp"
#include "object.hpp"
#include "light.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "lighting.hpp"
#include "renderer.hpp"
#include "canvas.hpp"
#include "triangle.hpp"
#include "sphere.hpp"
#include "plane.hpp"

class Raytracer{

    public:
        Raytracer(Scene scene, Camera camera, Canvas canvas);
        Raytracer();
        ~Raytracer();
        void setCanvasSize(int width,int height);
        void setCameraPosition(Vector3 location, float field_of_view); 
        void addSceneLight(Vector3 location, Vector3 intensity);
        void addTriangle(Vector3 a,Vector3 b,Vector3 c, Color color);
        void addSphere(Vector3 location, int radius, Color color);
        void addPlane(Vector3 location,Vector3 normal, Color color);
        void renderScene();
    private:
        Scene scene;
        Camera camera;
        Canvas canvas;
};

#endif //RAYTRACER_HPP