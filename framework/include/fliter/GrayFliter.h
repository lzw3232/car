#ifndef __FRAMEWORK_GRAYFLITER_H__
#define __FRAMEWORK_GRAYFLITER_H__

#include "../../include/fliter/Fliter.h"

namespace lzw{

    class GrayFliter:public Fliter
    {
    private:
        /* data */
    public:
        GrayFliter(PixelMtrix *pixelMtrix);
        ~GrayFliter();

        PixelMtrix *doFliter();
    };

    
    
    
}

#endif //! __FRAMEWORK_GRAYFLITER_H__