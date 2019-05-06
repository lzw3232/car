#include "../../include/cnn/ConvertionLayer.h"
#include<stdlib.h>
#include<math.h>

using namespace lzw;
using namespace lzw::cnn;

ConvertionLayer::ConvertionLayer(int width, int height, int batchSize, std::vector<double **> values, ConvertionKernel *w):Layer(width,height,batchSize,values,w)
{

}

ConvertionLayer::~ConvertionLayer()
{
}

ConvertionKernel *generateConvertionKernel(Vector *v, KernelGenerateMode kernelMode){
    ConvertionKernel *kernel = new ConvertionKernel(v->getX(),v->getY());
    switch (kernelMode)
    {
        case RANDOM:{
            /* code */
            random_gen:
            double **mtrix=new double*[v->getY()];
            for(int i=0; i<v->getY();i++){
                mtrix[i] = new double[v->getX()];
                for(int j=0;j<v->getX();j++){
                    mtrix[i][j]=rand()%10;
                }
            }
            kernel->setW(mtrix);
            return kernel;
            break;
        }
        default:
            goto random_gen;
            break;
    }
}


void ConvertionLayer::convolution(bool isFirstEpouch,Vector *v, KernelGenerateMode kernelMode){
    if(isFirstEpouch){
        this->setw(generateConvertionKernel(v,kernelMode));
    }
    std::vector<double **> values;
    for(int size=0;size<this->getbatchSize();size++){
        double **mtrix=new double*[this->getHeight()-(int)(2*floor(this->getw()->getHeight()/2))];
        for(int row=0;row<this->getHeight(); row++){
            mtrix[row]=new double[this->getWidth()-(int)(2*floor(this->getw()->getWidth()/2))];
            for(int col=0; col<this->getWidth();col++){
                int sum=0;
                for(int i=0; i<this->getw()->getHeight();i++){
                    for(int j=0;j<this->getw()->getWidth();j++){
                        sum+=this->getvalues().at(size)[row+i][col+j]*this->getw()->getW()[i][j];
                    }
                }
                mtrix[row][col]=sum;
            }
        }
        values.push_back(mtrix);
    }
    int w=this->getHeight()-(int)(2*floor(this->getw()->getHeight()/2));
    int h=this->getWidth()-(int)(2*floor(this->getw()->getWidth()/2));
    this->afterConvertionLayer = new ConvertionLayer(w,h,this->getbatchSize(),values,this->getw());
}

