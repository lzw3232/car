#ifndef __FRAMEWORK_CNN_LAYER_H__
#define __FRAMEWORK_CNN_LAYER_H__

#include "../../include/cnn/ConvertionKernel.h"
#include "../../include/cnn/math/Vector.h"
#include "../../include/image/PixelMtrix.h"
#include "../../include/cnn/common/SigMoidActivation.h"

#include <vector>

namespace lzw{
		namespace cnn{
	class Layer{
		private:
			int width;
			int height;
			
			int batchSize;
			
			std::vector<double **> values; // batch

			ConvertionKernel *w;

			double b;

			ActivationFunctionType activationFunctionType;
			Activation *activation;
			void (*CustomizeActivationFuntion)(int width,int height, double **values);

		public:
            Layer();
			Layer(int width, int height, int batchSize, std::vector<double **> values);
			Layer(int width, int height, int batchSize, std::vector<double **> values, ConvertionKernel *w);
			Layer(int width, int height, int batchSize, std::vector<PixelMtrix *> values, ConvertionKernel *w);

			virtual void convolution(bool isFirstEpouch,Vector *v, KernelGenerateMode kernelMode) = 0;

            // int setWidth(int width){this->width=width;};
            // int setHeight(int height){return this->height;};
            // int setbatchSize(){return this->batchSize;};
            // std::vector<double **> setvalues(){return this->values;};
            // ConvertionKernel *setw(){return this->w;};

            int getWidth(){return this->width;};
            int getHeight(){return this->height;};
            int getbatchSize(){return this->batchSize;};
            void setvalues(std::vector<double **> values){this->values=values;};
            std::vector<double **> getvalues(){return this->values;};
            void setw(ConvertionKernel *w){this->w=w;};
            ConvertionKernel *getw(){return this->w;};

			void setActivationFunctionType(ActivationFunctionType activationFunctionType){this->activationFunctionType=activationFunctionType;};
			ActivationFunctionType getActivationFunctionType(){return this->activationFunctionType;};

			void setActivationFunction(Activation *activation){this->activation=activation;};
			Activation *getActivationFunction(){return this->activation;};

			void setb(double b){this->b=b;};
			double getb(){return this->b;};


			~Layer();
	};
		};
};

#endif // ! __FRAMEWORK_CNN_LAYER_H__