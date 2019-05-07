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
				std::vector<Vector *> wHeightWidthPairs){


	this->sizeOfPoollingLayer = sizeOfPoollingLayer;
	this->sizeOfConvertionLayer = sizeOfConvertionLayer;
	this->batchSize = batchSize;
	this->epochNum = epochNum;
    this->layer=layer;
    this->kernelMode=kernelMode;
    this->wHeightWidthPairs=wHeightWidthPairs;
	this->init();
}


void CNN::init(){
	this->firstEpoch();
}

void CNN::train(){
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
	for(int layerNum = 0; layerNum<sizeOfConvertionLayer; layerNum++){
		this->convertionLayers.push_back(t_layer);
		t_layer->convolution(1,this->wHeightWidthPairs.at(layerNum),this->kernelMode);
        t_layer = t_layer->getAfterConvertionLayer();
	}
	polling();
	fullConnect();
}

void CNN::epoch(){
	for(int layerNum = 0; layerNum<sizeOfConvertionLayer; layerNum++){
		
	}
	polling();
	fullConnect();
}

void CNN::forward(){
	
}

void CNN::polling(){
	PoollingLayer *p_layer = this->convertionLayers.at(this->sizeOfConvertionLayer-1)->getAfterConvertionLayer()->castToPoollingLayer();
	for(int layerNum = 0; layerNum<sizeOfPoollingLayer; layerNum++){
		this->poollingLayers.push_back(p_layer);
		p_layer->convolution(1,this->wHeightWidthPairs.at(layerNum),KernelGenerateMode::MAX_POOLLING);
        p_layer = p_layer->getAfterPoollingLayer();
	}
	
}

void CNN::fullConnect(){

}