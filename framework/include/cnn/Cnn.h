#ifndef __FRAMEWORK_CNN_H__
#define __FRAMEWORK_CNN_H__

#include <vector>
#include "../../include/cnn/Layer.h"
#include "../../include/cnn/ConvertionLayer.h"
#include "../../include/cnn/PoollingLayer.h"
#include "../../include/cnn/FullyConnectedLayer.h"
#include "../../include/cnn/math/Vector.h"


namespace lzw{
	namespace cnn{
		class CNN{
			private:
				std::vector<ConvertionLayer*> convertionLayers;
				std::vector<PollingLayer*> pollingLayers;
				std::vector<FullyConnectedLayer*> fullyConnectedLayers;
                ConvertionLayer *layer;

                KernelGenerateMode kernelMode;
                
                std::vector<Vector *> wHeightWidthPairs;

				int	sizeOfConvertionLayer;

				int	epochNum;

				int batchSize;

				int loss;

				void init();

				void forward();
				void polling();
				void fullConnect();



				void firstEpoch();
				void epoch();


			public:

				CNN();

				void input(ConvertionLayer *layer, int sizeOfConvertionLayer, int batchSize, int epochNum, KernelGenerateMode kernelMode, std::vector<Vector *> wHeightWidthPairs);

				void train();

				void generateModel();

				~CNN();
		};
	};
};

#endif //!  __FRAMEWORK_CNN_H__