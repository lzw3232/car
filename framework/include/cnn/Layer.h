#ifndef __FRAMEWORK_CNN_LAYER_H__
#define __FRAMEWORK_CNN_LAYER_H__

#include "../../include/cnn/ConvertionKernel.h"
#include "../../include/cnn/math/Vector.h"
#include "../../include/image/PixelMtrix.h"

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
            std::vector<double **> getvalues(){return this->values;};
            void setw(ConvertionKernel *w){this->w=w;};
            ConvertionKernel *getw(){return this->w;};

			~Layer();
	};
		};
};

#endif // ! __FRAMEWORK_CNN_LAYER_H__