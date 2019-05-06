#ifndef __FRAMEWORK_CNN_FULLY_CONNECTED_LAYER_H__
#define __FRAMEWORK_CNN_FULLY_CONNECTED_LAYER_H__

#include "../../include/cnn/Layer.h"

namespace lzw{
		namespace cnn{
	class FullyConnectedLayer : public Layer{
		private:

		public:
			FullyConnectedLayer();
			~FullyConnectedLayer();
	};
		};
};

#endif // ! __FRAMEWORK_CNN_FULLY_CONNECTED_LAYER_H__