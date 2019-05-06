#include "../../include/location/Locate.h"

#include <iostream>
#include <math.h>

using namespace lzw;

Locate::Locate(PixelMtrix *pixelMtrix)
{
    this->pixelMtrix=pixelMtrix;
}

Locate::~Locate()
{
}

PixelMtrix *Locate::doLocate(){
    int MAX_ERROR=30;
    int init_width;
    int init_height;
    int init_rows;
    int init_cols;

    for (int rows = 0; rows < this->pixelMtrix->getHeight(); rows++) {
        if(rows==this->pixelMtrix->getHeight()-1){
            init_width=this->pixelMtrix->getWidth();
            init_height=this->pixelMtrix->getHeight();
            init_rows=0;
            init_cols=0;
            //std::cout<<rows<<" "<<cols<<std::endl;
            //std::cout<<width<<" "<<height<<std::endl;
            rows=this->pixelMtrix->getHeight();
            break;
        }
        for (int cols = 0; cols < this->pixelMtrix->getWidth(); cols ++) {
            if(this->GeneralColor(rows,cols)){
                //计算高度
                int height=0;
                int max_height=0;
                for (int i = rows; i < this->pixelMtrix->getHeight(); i++) {
                    height++;
                    if(!this->GeneralColor(i,cols)){
                        max_height++;
                    }
                    else{
                        max_height=0;
                    }
                    if(max_height>MAX_ERROR){
                        height-=max_height;
                        break;
                    }
                }

                //计算宽度
                int width=0;
                int max_width=0;
                for (int i = cols; i < this->pixelMtrix->getWidth(); i++) {
                    width++;
                    if(!this->GeneralColor(rows,i)){
                        max_width++;
                    }
                    else{
                        max_width=0;
                    }
                    if(max_width>MAX_ERROR){
                        width-=max_width;
                        break;
                    }
                }

                if(floor(width/height)==3 && width>=10 && height>=10){
                    init_width=width;
                    init_height=height;
                    init_rows=rows;
                    init_cols=cols;
                    //std::cout<<rows<<" "<<cols<<std::endl;
                    //std::cout<<width<<" "<<height<<std::endl;
                    rows=this->pixelMtrix->getHeight();
                    break;
                }

            }
        }
    }


    PixelMtrix *regin_pixelMtrix = new PixelMtrix();
    regin_pixelMtrix->setWidth(init_width);
    regin_pixelMtrix->setHeight(init_height);
    Pixel **pixels = new Pixel*[init_height];

    for (int rows = 0; rows < (init_height); rows++) {
        pixels[rows]=new Pixel[init_width];
        for (int cols = 0; cols < (init_width); cols ++) {
            pixels[rows][cols]= this->pixelMtrix->getPixel()[rows+init_rows][cols+init_cols];
        }
    }

    regin_pixelMtrix->setPixels(pixels);

    return regin_pixelMtrix;
    
}

bool Locate::GeneralColor(int rows,int cols){
    int r=this->pixelMtrix->getPixel()[rows][cols].getColor()->getR();
    int g=this->pixelMtrix->getPixel()[rows][cols].getColor()->getG();
    int b=this->pixelMtrix->getPixel()[rows][cols].getColor()->getB();
    if((r<=80)&&(r>=0)&&(g<=100)&&(g>=30)&&(b<=160)&&(b>=100)){
        return true;
    }
    return false;
}
