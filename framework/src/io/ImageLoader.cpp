#include "../../include/io/ImageLoader.h"

using namespace lzw;

ImageLoader::ImageLoader(ImageFormat format){
    io=new IOManager();
}

ImageLoader::~ImageLoader(){
    delete io;
    delete pixels;
}