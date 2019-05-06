#include "../../include/image/PixelMtrix.h"
#include <iostream>

using namespace lzw;

PixelMtrix::PixelMtrix(/* args */)
{
}

PixelMtrix::PixelMtrix(int width,int height)
{
    this->width = width;
    this->height = height;
}

PixelMtrix::~PixelMtrix()
{
}

void PixelMtrix::setData(int num_components,unsigned char *buffer){
    this->pixels=new Pixel*[this->height];
    //std::cout<<*buffer<<std::endl;
    for (int rows = 0; rows < this->height; rows++) {
        this->pixels[rows]=new Pixel[this->width];
        for (int cols = 0; cols < this->width; cols ++) {  
                Pixel *pixel = new Pixel();
                pixel->setColor(new Color(
                buffer[rows*this->width*num_components+cols*num_components+0],
                buffer[rows*this->width*num_components+cols*num_components+1],
                buffer[rows*this->width*num_components+cols*num_components+2]));
                this->pixels[rows][cols]= *pixel;
        }
    }  
}
