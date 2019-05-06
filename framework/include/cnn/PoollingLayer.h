#ifndef __FRAMEWORK_CNN_POLLING_LAYER_H__
#define __FRAMEWORK_CNN_POLLING_LAYER_H__

#include "../../include/cnn/Layer.h"

namespace lzw{
		namespace cnn{
	class PollingLayer : public Layer{
		private:

		public:
			PollingLayer();
			~PollingLayer();
	};
		};
};

#endif // ! __FRAMEWORK_CNN_POLLING_LAYER_H__