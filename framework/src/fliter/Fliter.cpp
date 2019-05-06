#include "../../include/fliter/Fliter.h"

using namespace lzw;

Fliter::Fliter(PixelMtrix *pixelMtrix,FliterMode fliterMode){
    this->pixelMtrix=pixelMtrix;
    this->fliterMode=fliterMode;
}

Fliter::Fliter::~Fliter()
{
}