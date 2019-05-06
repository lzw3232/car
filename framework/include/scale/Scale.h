#ifndef __FRAMEWORK_SCALE_H__
#define __FRAMEWORK_SCALE_H__

#include "../../include/image/PixelMtrix.h"
#include <vector>

namespace lzw{
    class Scale{
        private:

        int distW;
        int distH;
        PixelMtrix *pixel;

        public:
        Scale(int w,int h);
        Scale(int w,int h,PixelMtrix *pixel);
        int F(int p,int q);

        PixelMtrix *doScale();
        ~Scale();

    };
    
    
}

#endif //! __FRAMEWORK_SCALE_H__