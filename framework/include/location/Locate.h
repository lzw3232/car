#ifndef __FRAMEWORK_LOCATION_H__
#define __FRAMEWORK_LOCATION_H__

#include "../../include/image/PixelMtrix.h"

namespace lzw{

    class Locate
    {
    private:
        /* data */
        PixelMtrix *pixelMtrix;
    public:
        Locate(PixelMtrix *pixelMtrix);
        ~Locate();

        PixelMtrix *doLocate();
        PixelMtrix *getpixelMtrix(){return this->pixelMtrix;};
        bool GeneralColor(int rows,int cols);
    };
    

    
    
    
};

#endif //! __FRAMEWORK_LOCATION_H__

