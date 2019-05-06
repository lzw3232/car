#include "../../include/fliter/DenoiseFliter.h"

using namespace lzw;

DenoiseFliter::DenoiseFliter(PixelMtrix *pixelMtrix):Fliter(pixelMtrix,FliterMode::DENOISE_FLITER)
{
}

DenoiseFliter::~DenoiseFliter()
{
}

PixelMtrix *DenoiseFliter::doFliter(){
    for(int rows=0; rows<this->getPixelMtrix()->getHeight();rows++){
        for(int cols=0; cols<this->getPixelMtrix()->getWidth();cols++){
            Pixel pixel = this->getPixelMtrix()->getPixel()[rows][cols];
            int isNoise = 0;
            if(pixel.getColor()->getR() == 0x0){
                if(rows == 0 && cols == 0){
                    Pixel rightPixel = this->getPixelMtrix()->getPixel()[rows][cols+1];
                    Pixel bottomPixel = this->getPixelMtrix()->getPixel()[rows+1][cols];
                    if(rightPixel.getColor()->getR() == 0xFF && bottomPixel.getColor()->getR()== 0xFF){
                        isNoise = 1;
                    }
                }
                else if (rows == 0 && cols == (this->getPixelMtrix()->getWidth()-1)) {
                    Pixel leftPixel = this->getPixelMtrix()->getPixel()[rows][cols-1];
                    Pixel bottomPixel = this->getPixelMtrix()->getPixel()[rows+1][cols];
                    if(leftPixel.getColor()->getR() == 0xFF && bottomPixel.getColor()->getR() == 0xFF){
                        isNoise = 1;
                    }
                }
                else if (rows == (this->getPixelMtrix()->getHeight()-1) && cols == 0) {
                    Pixel rightPixel = this->getPixelMtrix()->getPixel()[rows][cols+1];
                    Pixel topPixel = this->getPixelMtrix()->getPixel()[rows-1][cols];
                    if(rightPixel.getColor()->getR() == 0xFF && topPixel.getColor()->getR() == 0xFF){
                        isNoise = 1;
                    }
                }
                else if (rows == (this->getPixelMtrix()->getHeight()-1) &&cols == (this->getPixelMtrix()->getWidth()-1)) {
                    Pixel leftPixel = this->getPixelMtrix()->getPixel()[rows][cols-1];
                    Pixel topPixel = this->getPixelMtrix()->getPixel()[rows-1][cols];
                    if(leftPixel.getColor()->getR() == 0xFF && topPixel.getColor()->getR()== 0xFF){
                        isNoise = 1;
                    
                }
                }
                else if (rows == 0) {
                    Pixel leftPixel = this->getPixelMtrix()->getPixel()[rows][cols-1];
                    Pixel bottomPixel = this->getPixelMtrix()->getPixel()[rows+1][cols];
                    Pixel rightPixel = this->getPixelMtrix()->getPixel()[rows][cols+1];
                    if(leftPixel.getColor()->getR() == 0xFF && bottomPixel.getColor()->getR()== 0xFF && rightPixel.getColor()->getR()== 0xFF){
                        isNoise = 1;
                    }
                }
                else if (cols == 0) {
                    Pixel topPixel = this->getPixelMtrix()->getPixel()[rows-1][cols];
                    Pixel bottomPixel = this->getPixelMtrix()->getPixel()[rows+1][cols];
                    Pixel rightPixel = this->getPixelMtrix()->getPixel()[rows][cols+1];
                    if(topPixel.getColor()->getR() == 0xFF && bottomPixel.getColor()->getR()== 0xFF && rightPixel.getColor()->getR()== 0xFF){
                        isNoise = 1;
                    }
                }
                else if (rows == (this->getPixelMtrix()->getHeight()-1)) {
                    Pixel topPixel = this->getPixelMtrix()->getPixel()[rows-1][cols];
                    Pixel leftPixel = this->getPixelMtrix()->getPixel()[rows][cols-1];
                    Pixel rightPixel = this->getPixelMtrix()->getPixel()[rows][cols+1];
                    if(topPixel.getColor()->getR() == 0xFF && leftPixel.getColor()->getR()== 0xFF && rightPixel.getColor()->getR()== 0xFF){
                        isNoise = 1;
                    }
                }
                else if (cols == (this->getPixelMtrix()->getWidth()-1)) {
                    Pixel topPixel = this->getPixelMtrix()->getPixel()[rows-1][cols];
                    Pixel leftPixel = this->getPixelMtrix()->getPixel()[rows][cols-1];
                    Pixel bottomPixel = this->getPixelMtrix()->getPixel()[rows+1][cols];
                    if(topPixel.getColor()->getR() == 0xFF && leftPixel.getColor()->getR()== 0xFF && bottomPixel.getColor()->getR()== 0xFF){
                        isNoise = 1;
                    }
                }
                else
                {
                    Pixel topPixel = this->getPixelMtrix()->getPixel()[rows-1][cols];
                    Pixel leftPixel = this->getPixelMtrix()->getPixel()[rows][cols-1];
                    Pixel bottomPixel = this->getPixelMtrix()->getPixel()[rows+1][cols];
                    Pixel rightPixel = this->getPixelMtrix()->getPixel()[rows][cols+1];
                    if(topPixel.getColor()->getR() == 0xFF && leftPixel.getColor()->getR()== 0xFF && bottomPixel.getColor()->getR()== 0xFF&& rightPixel.getColor()->getR()== 0xFF){
                        isNoise = 1;
                    }
                }
            }

            if(isNoise==1){
                this->getPixelMtrix()->setPixel(
                    rows,
                    cols,
                    new Pixel(new Color(
                        0xFF,
                        0xFF,
                        0xFF
                    )));
            }

        }
    }
    return this->getPixelMtrix();
}

