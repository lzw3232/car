#include "../../include/cnn/ConvertionKernel.h"

using namespace lzw;
using namespace lzw::cnn;

double **generateOperator(int w, int h,double *arr){
	double** x = new double*[h];
	for(int i = 0; i<h; i++){
		x[i] = new double[w];
		for(int j = 0;j<w;j++){
			x[h][w] = *arr;
			arr++;
		}
	}
	return x;
}

ConvertionKernel::ConvertionKernel(){
}

ConvertionKernel::ConvertionKernel(int width,int height){
    this->width=width;
    this->height=height;
}

ConvertionKernel::ConvertionKernel(int width,int height, double **w){
    this->width=width;
    this->height=height;
    this->w=w;
}

ConvertionKernel::~ConvertionKernel(){
	
}