#include "../../../include/cnn/common/SigMoidActivation.h"
#include<cmath>
#include<iostream>

using namespace lzw;


SigMoidActivation::SigMoidActivation():Activation(ActivationFunctionType::ACTIVATION_FUNCTION_SIGMOID)
{
}

SigMoidActivation::~SigMoidActivation()
{
}

void SigMoidActivation::doActive(int width,int height,double **values){
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            values[row][col]=1/(1+exp(-values[row][col]));
        }
    }
}