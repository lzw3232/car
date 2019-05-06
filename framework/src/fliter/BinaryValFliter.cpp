#include "../../include/fliter/BinaryValFliter.h"

using namespace lzw;

BinaryValFliter::BinaryValFliter(PixelMtrix *pixelMtrix) : Fliter(pixelMtrix, FliterMode::BINARY_FLITER){

}

PixelMtrix *BinaryValFliter::doFliter(){
    for(int rows=0; rows<this->getPixelMtrix()->getHeight();rows++){
        for(int cols=0; cols<this->getPixelMtrix()->getWidth();cols++){
            Pixel pixel = this->getPixelMtrix()->getPixel()[rows][cols];
            this->getPixelMtrix()->setPixel(
                rows,
                cols,
                new Pixel(new Color(
                    pixel.getColor()->getBinaryVal(),
                    pixel.getColor()->getBinaryVal(),
                    pixel.getColor()->getBinaryVal()
                )
                )
            );
        }
    }
    return this->getPixelMtrix();
}

BinaryValFliter::~BinaryValFliter()
{
}