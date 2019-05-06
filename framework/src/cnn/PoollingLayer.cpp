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

};

PoollingLayer::~PoollingLayer()
{
}

