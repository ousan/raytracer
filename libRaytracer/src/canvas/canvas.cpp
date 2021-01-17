#include "canvas.hpp"

Canvas::Canvas()
: width(640), height(480)
{
};

Canvas::Canvas(int _width, int _height) 
: width(_width), height(_height)
{
};

int Canvas::getCanvasWidth() const 
{ 
    return width; 
}

int Canvas::getCanvasHeight() const 
{ 
    return height; 
}

int Canvas::setCanvasSize(int _height, int _width) 
{ 
    width = _width; 
    height = _height;
}


