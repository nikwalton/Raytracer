#include "color.hpp"
#include <vector>

#ifndef CANVAS_HPP
#define CANVAS_HPP

class Canvas
{
public:
    Canvas(){}
    Canvas(unsigned short int height, unsigned short int width);

    unsigned short int GetHeight();
    unsigned short int GetWidth();
    std::vector<std::vector<Color>> GetPixels();

    void SetHeight(unsigned short int newHeight);
    void SetWidth(unsigned short int newWidth);
    void SetPixels(std::vector<std::vector<Color>> newPixels);
    

    void WritePixel(Canvas canvas, unsigned short int x, unsigned short int y);
    

private:
    //if you need more than 60k pixels height and width wise idk what to tell you
    //i'd honestly be more impressed than anything
    unsigned short int width;
    unsigned short int height;

    std::vector<std::vector<Color>> pixels;
};
#endif