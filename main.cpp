#include "raytracer.hpp"

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <typeinfo>

using namespace std;

void example() {
    printf("Raytracerlibrary demo...\n");
    Raytracer raytracer;

    /*Setting canvas size*/
    int width = 1080;
    int height = 800;
    raytracer.setCanvasSize(width, height);

    /*Addingscene light with intensity*/
    Vector3 l_location = Vector3(0,20,35);
    Vector3 l_intensity = Vector3(1.4);
    raytracer.addSceneLight(l_location, l_intensity);

    /*Setting camera positin with field of view parameters*/
    Vector3 c_location = Vector3(0,20,-20);
    float fov = 30.0;
    raytracer.setCameraPosition(c_location, fov);
    
    /*Adding triangles*/
    raytracer.addTriangle( Vector3(0, 4, -30), Vector3(5, -4, -30), Vector3(-5, -4, -30), Color(165, 10, 14));
    raytracer.addTriangle(Vector3(0, -4+1, 0), Vector3(1, -4+-1, 0), Vector3(-1, -4+-1, 0), Color(165, 10, 14));

    /*Adding spheres*/
    raytracer.addSphere(Vector3(0, 4, 30), 0.2, Color(255));
    raytracer.addSphere(Vector3(5, -4, 30), 0.2, Color(255));
    raytracer.addSphere(Vector3(-5, -4, 30), 0.2, Color(255));
    raytracer.addSphere(Vector3(0, -10004, 20), 10000,Color(51, 51, 51));
    raytracer.addSphere(Vector3(0, 0, 20), 4, Color(165, 10, 14));
    raytracer.addSphere(Vector3(5, 0, 25), 3, Color(6, 72, 111));
    raytracer.addSphere(Vector3(5, -1, 15), 2, Color(235, 179, 41));
    raytracer.addSphere(Vector3(-3.5, -1, 10), 2, Color(8, 88, 56));
    raytracer.addSphere(Vector3(-5.5, 0, 15), 3, Color(51, 51, 51));

    /*Rendering scene*/
    raytracer.renderScene();

}

int main() {
  example();
  
  return 0;
}