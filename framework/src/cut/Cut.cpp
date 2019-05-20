#include "../../include/cut/Cut.h"
#include <iostream>

using namespace lzw;

    
Cut::Cut(PixelMtrix *pixelMtrix)
{
    this->pixelMtrix = pixelMtrix;
}

Cut::~Cut()
{
}

std::vector<Rect*> Cut::doCut(){
    int width=this->getPixelMtrix()->getWidth();
    int height=this->getPixelMtrix()->getHeight();
    int *blackPoint = (int *)malloc(width*sizeof(int));
    int average = 0;
    for(int cols=0; cols<width;cols++){
        int sum=0;
        for(int rows=0; rows<height;rows++){
            if(this->getPixelMtrix()->getPixel()[rows][cols].getColor()->getR() == 0x0){
                sum++;
            }
        }
        
        sum = (sum<5) ? 0:sum;
        blackPoint[cols] = sum;
    }


    // for(int cols=0; cols<width;cols++){
    //     std::cout<<blackPoint[cols]<<" ";
    // }
    // std::cout<<std::endl;

    std::vector<int> cut_point;
    
    for(int cols=0; cols<width;cols++){
        if(cols==5&&cut_point.empty()){
            cut_point.push_back(0);
        }
        if(blackPoint[cols]==0){
            int zero_sum=1;
            for(int i=cols+1; i<width;i++){
                if(blackPoint[i]==0){
                    zero_sum++;
                }
                else{
                    break;
                }
            }
            if(zero_sum>2){
                cut_point.push_back((zero_sum+cols+cols)/2);
                cols=zero_sum+cols;
            }
        }
    }

    for(int cols=0; cols<cut_point.size()-1;cols++){
        Rect *regin = new Rect(cut_point.at(cols),cut_point.at(cols+1));
        regin->setHeight(height);
        this->rectArray.push_back(regin);
    }

    // for(int cols=0; cols<cut_point.size();cols++){
    //     std::cout<<cut_point.at(cols)<<" ";
    // }
    // std::cout<<std::endl;

    delete blackPoint;
    return this->rectArray;
}


PixelMtrix *Cut::clip(PixelMtrix *pixelMtrix,Rect *rect){
    PixelMtrix *regin_pixelMtrix = new PixelMtrix();
    regin_pixelMtrix->setWidth(rect->getWidth());
    regin_pixelMtrix->setHeight(rect->getHeight());
    Pixel **pixels = new Pixel*[rect->getHeight()];
    //std::cout<<rect->getWidth()<<" "<<rect->getHeight()<<std::endl;

    for (int rows = 0; rows < rect->getHeight(); rows++) {
        pixels[rows]=new Pixel[rect->getWidth()];
        for (int cols = 0; cols < rect->getWidth(); cols ++) {
                pixels[rows][cols]= pixelMtrix->getPixel()[rows][rect->getPosX()+cols];
        }
    } 
    regin_pixelMtrix->setPixels(pixels);

    return regin_pixelMtrix;
}