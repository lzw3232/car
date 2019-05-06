#ifndef __FRAMEWORK_BINARYVALFLITER_H__
#define __FRAMEWORK_BINARYVALFLITER_H__

#include "../../include/fliter/Fliter.h"

namespace lzw{

    class BinaryValFliter:public Fliter
    {
    private:
        /* data */
    public:
        BinaryValFliter(PixelMtrix *pixelMtrix);
        ~BinaryValFliter();

        PixelMtrix *doFliter();
    };

    
    
    
}

#endif //! __FRAMEWORK_BINARYVALFLITER_H__