#ifndef __FRAMEWORK_FLITER_H__
#define __FRAMEWORK_FLITER_H__

#include "../../include/image/PixelMtrix.h"

namespace lzw{

    typedef enum FliterMode{
        GRAY_FLITER,
        BINARY_FLITER,
        DENOISE_FLITER
    }FliterMode;

    class Fliter
    {
    private:
        /* data */
        FliterMode fliterMode;
        PixelMtrix *pixelMtrix;

    public:
        Fliter(PixelMtrix *pixelMtrix,FliterMode fliterMode);
        ~Fliter();

        virtual PixelMtrix *doFliter()=0;

        PixelMtrix *getPixelMtrix(){return this->pixelMtrix;};
    };
    
    
}

#endif //! __FRAMEWORK_FLITER_H__