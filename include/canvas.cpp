#include "canvas.hpp"

/// @brief Creates a new canvas. Note that to create a canvas of dimensions (Height x, Width y), 
/// it will be entered as (y, x)
/// @param width The width of the canvas
/// @param height The height of the canvas
Canvas::Canvas(unsigned short int width, unsigned short int height)
{
    this->height = height;
    this->width = width;

    Color white(0,0,0);
    std::vector<std::vector<Color>> pix(height, std::vector<Color> (width, white));

    this->pixels = pix;
}

unsigned short int Canvas::GetHeight()
{
    return this->height;
}

unsigned short int Canvas::GetWidth()
{
    return this->width;
}

std::vector<std::vector<Color>> Canvas::GetPixels()
{
    return this->pixels;
}

/// @brief Returns the pixel at the specified location. Note that Width is the first argument not Height
/// @param y The width location you wish to access
/// @param x The Height location you wish to accss
/// @return Pixel at location (width y, height x)
Color Canvas::PixelAt(unsigned short int y, unsigned short int x)
{
    return pixels[x][y];
}

void Canvas::SetHeight(unsigned short int newHeight)
{
    this->height = newHeight;
}
void Canvas::SetWidth(unsigned short int newWidth)
{
    this->width = newWidth;
}

void Canvas::SetPixels(std::vector<std::vector<Color>> newPixels)
{
    this->pixels = newPixels;
}

/// @brief Writes to the pixel located at width y and height x
/// @param y The width you wish to write to 
/// @param x The height you wish to write to
/// @param pixel The new color pixel that is to be written
void Canvas::WritePixel(unsigned short int y, unsigned short int x, Color pixel)
{
    this->pixels[x][y] = pixel;
}


/// @brief normalizes a foat value to be between 0 - 255
/// @param value the value to be normalized
/// @return a integer between 0 and 255
int Canvas::NormalizePixel(float value)
{
    int result;

    if (value <= 0)
    {
        return 0;
    }
    else if (value >= 1)
    {
        return 255;
    }
    else
    {
        result = std::round(value * 255);
        return result;
    }
}

std::string Canvas::CanvasToPPM()
{
    std::stringstream ss;

    ss << "P3\n" << this->GetWidth() <<" " << this->GetHeight() << "\n" << "255\n";

    std::vector<std::vector<Color>> tempPixels = this->GetPixels();
    
    int charCount = 0;
    for (auto row : tempPixels) 
    {
        for (auto col : row)
        {
            int red = this->NormalizePixel(col.GetRed());
            int green = this->NormalizePixel(col.GetGreen());
            int blue = this->NormalizePixel(col.GetBlue());
            
            //Inserting Red
            if (charCount + std::to_string(red).length() < 70)
            {
                ss << red;
                charCount = charCount + std::to_string(red).length();
            }
            else
            {
                ss.seekp(-1, ss.cur);
                ss << "\n";
                ss << red;
                charCount = std::to_string(red).length();
            }

            ss << " ";
            charCount = charCount + 1;
            //Inserting Green
            if (charCount + std::to_string(green).length() < 70)
            {
                ss << green;
                charCount = charCount + std::to_string(green).length();
            }
            else
            {
                ss.seekp(-1, ss.cur);
                ss << "\n";
                ss << green;
                charCount = std::to_string(green).length();
            }

            ss << " ";
            charCount = charCount + 1;
            //Inserting Blue
            if (charCount + std::to_string(blue).length() < 70)
            {
                ss << blue;
                charCount = charCount + std::to_string(blue).length();
            }
            else
            {
                ss.seekp(-1, ss.cur);
                ss << "\n";
                ss << blue;
                charCount = std::to_string(blue).length();
            }

            ss << " ";
            charCount = charCount + 1;
           // ss << this->NormalizePixel(col.GetRed()) << ' ' << this->NormalizePixel(col.GetGreen()) << ' '
             //   << this->NormalizePixel(col.GetBlue()) << ' ';
        }
        ss.seekp(-1, ss.cur);
        ss << "\n";
        charCount = 0;
    }

    std::string result = ss.str();

    return result;
}