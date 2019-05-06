#include "../../include/io/IOManager.h"
#include "../../include/log/Log.h"
#include<iostream>
#include <memory>
#include <fstream>

using namespace lzw;

void IOManager::loadFile(const char *filePath){
    std::streampos fileSize;
    std::ifstream file(filePath,std::ios::binary);

    file.seekg(0,std::ios::end);
    fileSize = file.tellg();

    this->bufferSize=fileSize;

    file.seekg(0,std::ios::beg);

    this->buffer=(char*)malloc(fileSize*sizeof(char));
    if(!this->buffer){
        Log("file load error:%s \n",filePath);
    }
    file.read(this->buffer,fileSize);
};

    
IOManager::IOManager(/* args */)
{
}

IOManager::~IOManager()
{
    free(this->buffer);
}