#ifndef __FRAMEWORK_CNN_CONVERTION_LAYER_H__
#define __FRAMEWORK_CNN_CONVERTION_LAYER_H__

#include "../../include/cnn/Layer.h"
#include "../../include/cnn/math/Vector.h"

namespace lzw{
		namespace cnn{
	class ConvertionLayer : public Layer{
		private:

        ConvertionLayer *afterConvertionLayer;

		public:
			ConvertionLayer(){};

			ConvertionLayer(int width, int height, int batchSize, std::vector<double **> values, ConvertionKernel *w);
			
			ConvertionLayer(int width, int height, int batchSize, std::vector<PixelMtrix *> values, ConvertionKernel *w);

			void convolution(bool isFirstEpouch,Vector *v, KernelGenerateMode kernelMode);

            ConvertionLayer *getAfterConvertionLayer(){return this->afterConvertionLayer;};

			~ConvertionLayer();
	};
		};
};

#endif // ! __FRAMEWORK_CNN_CONVERTION_LAYER_H__