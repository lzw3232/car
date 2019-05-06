#include "../../include/cnn/Layer.h"

using namespace lzw;
using namespace lzw::cnn;

Layer::Layer(){

}

Layer::Layer(int width, int height, int batchSize, std::vector<double **> values, ConvertionKernel *w):Layer(width,height,batchSize,values){
    this->w=w;
}

Layer::Layer(int width, int height, int batchSize, std::vector<double **> values){
    this->width=width;
    this->height=height;
    this->batchSize=batchSize;
    this->values=values;
}

Layer::Layer(int width, int height, int batchSize, std::vector<PixelMtrix *> values, ConvertionKernel *w){
    this->width=width;
    this->height=height;
    this->batchSize=batchSize;
    std::vector<double **> picture;
    for(int size=0;size<values.size();size++){
        double **mtrix=new double*[values.at(size)->getHeight()];
        for(int i=0; i<values.at(size)->getHeight();i++){
            mtrix[i] = new double[values.at(size)->getWidth()];
            for(int j=0;j<values.at(size)->getWidth();j++){
                mtrix[i][j]=values.at(size)->getPixel()[i][j].getColor()->getR();
            }
        }
        picture.push_back(mtrix);
    }
    this->values=picture;
    this->w=w;

}

Layer::~Layer()
{
}

