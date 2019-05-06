#include "../../include/fliter/GrayFliter.h"

using namespace lzw;

GrayFliter::GrayFliter(PixelMtrix *pixelMtrix) : Fliter(pixelMtrix, FliterMode::GRAY_FLITER){

}

PixelMtrix *GrayFliter::doFliter(){
    for(int rows=0; rows<this->getPixelMtrix()->getHeight();rows++){
        for(int cols=0; cols<this->getPixelMtrix()->getWidth();cols++){
            Pixel pixel = this->getPixelMtrix()->getPixel()[rows][cols];
            this->getPixelMtrix()->setPixel(
                rows,
                cols,
                new Pixel(new Color(
                    pixel.getColor()->getGray(),
                    pixel.getColor()->getGray(),
                    pixel.getColor()->getGray()
                )
                )
            );
        }
    }
    return this->getPixelMtrix();
}

GrayFliter::~GrayFliter()
{
}