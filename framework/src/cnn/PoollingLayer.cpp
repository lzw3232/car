#include "../../include/cnn/PoollingLayer.h"
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace lzw;
using namespace lzw::cnn;


PoollingLayer::PoollingLayer()
{
}

PoollingLayer::PoollingLayer(int width, 
                            int height, 
                            int batchSize, 
                            std::vector<double **> values 
                            ):Layer(width,height,batchSize,values)
{
}

void PoollingLayer::convolution(bool isFirstEpouch,Vector *v, KernelGenerateMode kernelMode){
    std::vector<double **> values;
    for(int size=0;size<this->getbatchSize();size++){
        double **mtrix=new double*[this->getHeight()/2];
        for(int row=0;row<this->getHeight()/2; row++){
            mtrix[row]=new double[this->getWidth()/2];
            for(int col=0; col<this->getWidth()/2;col++){
                double max=0;
                for(int i=0; i<2;i++){
                    for(int j=0;j<2;j++){
                        if(this->getvalues().at(size)[row*2+i][col*2+j]>max){
                            max=this->getvalues().at(size)[row*2+i][col*2+j];
                        }
                    }
                }
                mtrix[row][col]=max;
            }
        }
        values.push_back(mtrix);
    }
    int w=this->getHeight()/2;
    int h=this->getWidth()/2;
    if(isFirstEpouch){
        this->afterPoollingLayer = new PoollingLayer(w,h,this->getbatchSize(),values);
    }else{
        this->afterPoollingLayer->setvalues(values);
    }
    this->afterPoollingLayer->print();
};


void PoollingLayer::print(){
    std::cout<<this->getWidth()<<" "<<this->getHeight()<<std::endl;
}


FullyConnectedLayer *PoollingLayer::castToFullyConnectedLayer(){
    FullyConnectedLayer *p_layer = new FullyConnectedLayer(this->getWidth(),
                                                this->getHeight(),
                                                this->getbatchSize(),
                                                this->getvalues());
    // p_layer->setvalues = this->getvalues();
    // p_layer->setWidth = this->getWidth();
    // p_layer->setHeight = this->getHeight();
    // p_layer->setbatchSize = this->getbatchSize();
    return p_layer;
}

PoollingLayer::~PoollingLayer()
{
}

