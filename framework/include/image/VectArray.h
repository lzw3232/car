#ifndef __FRAMEWORK_VECTARRAY_H__
#define __FRAMEWORK_VECTARRAY_H__

#include "../../include/image/Vect.h"
#include <vector>

namespace lzw{
    
    class VectArray
    {
    private:
        /* data */
        std::vector<Vect*> vectArray;
    public:
        VectArray(/* args */);
        ~VectArray();
    };
    
};

#endif //! __FRAMEWORK_VECTARRAY_H__

