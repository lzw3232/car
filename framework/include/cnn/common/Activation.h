#ifndef __FRAMEWORK_SCTIVATION_H__
#define __FRAMEWORK_SCTIVATION_H__

#include <vector>

namespace lzw{

    typedef enum ActivationFunctionType{
        ACTIVATION_FUNCTION_CUSTOMIZE,
        ACTIVATION_FUNCTION_SIGMOID,
        ACTIVATION_FUNCTION_TANH,
        ACTIVATION_FUNCTION_RELU,
        ACTIVATION_FUNCTION_LEAKY_RELU,
        ACTIVATION_FUNCTION_ELU,
        ACTIVATION_FUNCTION_MAXOUT,
    }ActivationFunctionType;

	class Activation
    {
    private:
        ActivationFunctionType activationFunctionType;
    public:
        Activation(ActivationFunctionType activationFunctionType);

        virtual void doActive(int width,int height,double **values)  = 0;
        ~Activation();
    };
    

    
};

#endif //!  __FRAMEWORK_SCTIVATION_H__