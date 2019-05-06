#ifndef __FRAMEWORK_CUT_H__
#define __FRAMEWORK_CUT_H__

#include "../../include/image/PixelMtrix.h"
#include "../../include/image/Rect.h"
#include <vector>

namespace lzw{

    class Cut
    {
    private:
        /* data */
        PixelMtrix *pixelMtrix;
        std::vector<Rect *> rectArray;
        std::vector<PixelMtrix*> pixelMtrixs;

    public:
        Cut(PixelMtrix *pixelMtrix);
        ~Cut();

        std::vector<Rect*> doCut();

        std::vector<Rect*> getArray(){return this->rectArray;};

        PixelMtrix *getPixelMtrix(){return this->pixelMtrix;};

        PixelMtrix *clip(PixelMtrix *pixelMtrix,Rect *rect);
    };

    
    
    
}

#endif //! __FRAMEWORK_CUT_H__