#ifndef __FRAMEWORK_CNN_H__
#define __FRAMEWORK_CNN_H__

#include <vector>
#include "../../include/cnn/Layer.h"
#include "../../include/cnn/ConvertionLayer.h"
#include "../../include/cnn/PoollingLayer.h"
#include "../../include/cnn/FullyConnectedLayer.h"
#include "../../include/cnn/math/Vector.h"
#include "../../include/cnn/common/Activation.h"


namespace lzw{
	namespace cnn{
		class CNN{
			private:
				std::vector<ConvertionLayer *> convertionLayers;
				std::vector<PoollingLayer *> poollingLayers;
				std::vector<FullyConnectedLayer*> fullyConnectedLayers;
                ConvertionLayer *layer;

                KernelGenerateMode kernelMode;
                
                std::vector<Vector *> wHeightWidthPairs;

				int	sizeOfConvertionLayer;

				int	sizeOfPoollingLayer;

				int	epochNum;

				int batchSize;

				int loss;

				void init();

				void forward();
				void polling(bool isFirst);
				void fullConnect(bool isFirst);



				void firstEpoch();
				void epoch();

				ActivationFunctionType activationFunctionType;
				void (*customizeActivationFuntion)(int width,int height, double **values);

			public:

				CNN();

				void input(ConvertionLayer *layer, int sizeOfConvertionLayer,int sizeOfPoollingLayer, int batchSize, int epochNum, KernelGenerateMode kernelMode, std::vector<Vector *> wHeightWidthPairs,ActivationFunctionType activationFunctionType);
				void input(ConvertionLayer *layer, int sizeOfConvertionLayer,int sizeOfPoollingLayer, int batchSize, int epochNum, KernelGenerateMode kernelMode, std::vector<Vector *> wHeightWidthPairs,ActivationFunctionType activationFunctionType,void (*CustomizeActivationFuntion)(int width,int height, double **values));

				void train();

				void generateModel();

				~CNN();
		};
	};
};

#endif //!  __FRAMEWORK_CNN_H__