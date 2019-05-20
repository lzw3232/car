#ifndef __FRAMEWORK_SIGMOIDACTIVATION_H__
#define __FRAMEWORK_SIGMOIDACTIVATION_H__

#include <vector>
#include "./Activation.h"

namespace lzw{
    class SigMoidActivation:public Activation
    {
    private:
        /* data */
        
    public:
        SigMoidActivation();

        
        void doActive(int width,int height,double **values);
        ~SigMoidActivation();
    };
    
    
    
    
};

#endif //!  __FRAMEWORK_SIGMOIDACTIVATION_H__