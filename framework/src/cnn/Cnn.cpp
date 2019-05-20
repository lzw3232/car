#include "../../include/cnn/Cnn.h"
#include<iostream>

using namespace lzw;
using namespace lzw::cnn;

CNN::CNN(){

}

CNN::~CNN(){

}

void CNN::input(ConvertionLayer *layer, 
				int	sizeOfConvertionLayer, 
				int sizeOfPoollingLayer,
				int batchSize, 
				int epochNum, 
				KernelGenerateMode kernelMode,
				std::vector<Vector *> wHeightWidthPairs,
				ActivationFunctionType activationFunctionType){


	this->sizeOfPoollingLayer = sizeOfPoollingLayer;
	this->sizeOfConvertionLayer = sizeOfConvertionLayer;
	this->batchSize = batchSize;
	this->epochNum = epochNum;
    this->layer=layer;
    this->kernelMode=kernelMode;
    this->wHeightWidthPairs=wHeightWidthPairs;
	this->activationFunctionType = activationFunctionType;
}

void CNN::input(ConvertionLayer *layer, 
				int	sizeOfConvertionLayer, 
				int sizeOfPoollingLayer,
				int batchSize, 
				int epochNum, 
				KernelGenerateMode kernelMode,
				std::vector<Vector *> wHeightWidthPairs,
				ActivationFunctionType activationFunctionType,
				void (*CustomizeActivationFuntion)(int width,int height, double **values)){


	this->input(layer,sizeOfConvertionLayer,sizeOfPoollingLayer,batchSize,epochNum,kernelMode,wHeightWidthPairs,activationFunctionType);
	this->customizeActivationFuntion = CustomizeActivationFuntion;
}


void CNN::init(){
	this->firstEpoch();
}

void CNN::train(){
	this->init();
	int epoch = 0;
	while(epoch<this->epochNum){
		this->epoch();
		epoch++;
	}
}

void CNN::generateModel(){
 	// TODO: output model to file
}

void CNN::firstEpoch(){
	ConvertionLayer *t_layer = this->layer;
	t_layer->setActivationFunctionType(this->activationFunctionType);
	for(int layerNum = 0; layerNum<sizeOfConvertionLayer; layerNum++){
		this->convertionLayers.push_back(t_layer);
		t_layer->convolution(1,this->wHeightWidthPairs.at(layerNum),this->kernelMode);
        t_layer = t_layer->getAfterConvertionLayer();
	}
	polling(1);
	fullConnect(1);
}

void CNN::epoch(){
	ConvertionLayer *t_layer = this->layer;
	for(int layerNum = 0; layerNum<sizeOfConvertionLayer; layerNum++){
		t_layer->convolution(0,this->wHeightWidthPairs.at(layerNum),this->kernelMode);
        t_layer = t_layer->getAfterConvertionLayer();
	}
	polling(0);
	fullConnect(0);
}

void CNN::forward(){
	
}

void CNN::polling(bool isFirst){
	PoollingLayer *p_layer = this->convertionLayers.at(this->sizeOfConvertionLayer-1)->getAfterConvertionLayer()->castToPoollingLayer();
	for(int layerNum = 0; layerNum<sizeOfPoollingLayer; layerNum++){
		this->poollingLayers.push_back(p_layer);
		p_layer->convolution(isFirst,this->wHeightWidthPairs.at(layerNum),KernelGenerateMode::MAX_POOLLING);
        p_layer = p_layer->getAfterPoollingLayer();
	}
	
}

void CNN::fullConnect(bool isFirst){
	FullyConnectedLayer *p_layer = this->poollingLayers.at(this->sizeOfPoollingLayer-1)->getAfterPoollingLayer()->castToFullyConnectedLayer();
	p_layer->convolution(isFirst,this->wHeightWidthPairs.at(0),KernelGenerateMode::MAX_POOLLING);
}