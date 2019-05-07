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
        double **mtrix=new double*[this->getHeight()-v->getY()+1];
        for(int row=0;row<this->getHeight()-v->getY()+1; row++){
            mtrix[row]=new double[this->getWidth()-v->getX()+1];
            for(int col=0; col<this->getWidth()-v->getX()+1;col++){
                int sum=0;
                for(int i=0; i<v->getY();i++){
                    for(int j=0;j<v->getX();j++){
                        sum+=this->getvalues().at(size)[row+i][col+j];
                    }
                }
                mtrix[row][col]=sum;
            }
        }
        values.push_back(mtrix);
    }
    int w=this->getHeight()-v->getY()+1;
    int h=this->getWidth()-v->getX()+1;
    this->afterPoollingLayer = new PoollingLayer(w,h,this->getbatchSize(),values);
    this->afterPoollingLayer->print();
};


void PoollingLayer::print(){
    std::cout<<this->getWidth()<<" "<<this->getHeight()<<std::endl;
}

PoollingLayer::~PoollingLayer()
{
}

