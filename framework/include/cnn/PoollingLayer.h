#ifndef __FRAMEWORK_CNN_POOLLING_LAYER_H__
#define __FRAMEWORK_CNN_POOLLING_LAYER_H__

#include "../../include/cnn/Layer.h"
#include "../../include/cnn/FullyConnectedLayer.h"

namespace lzw{
	namespace cnn{
		class PoollingLayer : public Layer{
			private:

			PoollingLayer *afterPoollingLayer;

			public:
				PoollingLayer();
				PoollingLayer(int width, int height, int batchSize, std::vector<double **> values);
				~PoollingLayer();

				void convolution(bool isFirstEpouch,Vector *v, KernelGenerateMode kernelMode);
				PoollingLayer *getAfterPoollingLayer(){return this->afterPoollingLayer;};
				FullyConnectedLayer *castToFullyConnectedLayer();
				void print();
		};
	};
};

#endif // ! __FRAMEWORK_CNN_POOLLING_LAYER_H__