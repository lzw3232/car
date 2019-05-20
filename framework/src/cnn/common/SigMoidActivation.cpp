#include "../../../include/cnn/common/SigMoidActivation.h"
#include<math.h>
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
            values[row][col]=(double)(1.0/(1.0+exp(-(values[row][col]/255.0))));
        }
    }
}