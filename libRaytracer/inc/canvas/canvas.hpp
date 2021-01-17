#ifndef CANVAS_HPP
#define CANVAS_HPP

class Canvas
{
    public:
    Canvas();
    Canvas(int _width, int _height);
    int getCanvasWidth() const;
    int getCanvasHeight() const;
    int setCanvasSize(int height, int width);

    private:
        int width;
        int height;
};
#endif //CANVAS_HPP
