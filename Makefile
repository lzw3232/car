DEBUG=

#compiler
ifdef DEBUG
CXX=arm-linux-gnueabihf-g++
else
CXX=g++
endif

#include
ifdef DEBUG
INCLUDE_DIR=/home/lzw/jpeglib/include
INCLUDE_DIR+=-I$(BASE_DIR)/framework/include
else
INCLUDE_DIR=$(BASE_DIR)/framework/include
endif

INCLUDE_DIR+=-I$(BASE_DIR)/app/include
INCLUDE_DIR+=-I/usr/include/SDL2

LIBS_DIR=-L$(BASE_DIR)/jpeglib2/lib

#app
SRC=$(wildcard $(BASE_DIR)/app/src/*.cpp)

#framework
SRC+=$(wildcard $(BASE_DIR)/framework/src/*.cpp)


#build dir
BUILD_DIR=$(BASE_DIR)/app/build

#objs dir
OBJ_DIR=$(BASE_DIR)/app/obj

#asm dir
ASM_DIR=$(BASE_DIR)/app/asm


#build flags
CPP_FLAGS=-I$(INCLUDE_DIR) -std=c++11 -Wall
LINK_FLAGS=


#dir
BASE_DIR=/home/lzw/study/car

#extra lib
ifdef DEBUG
LIB=$(LIBS_DIR) -lstdc++ -ljpeg -lpthread
else
LIB=-lstdc++ -ljpeg -lSDL2 -lSDL2main `sdl2-config --cflags --libs` -lpthread
endif

ifdef DEBUG
run:clean all
	$(BUILD_DIR)/app
all: main.o JPGImageLoader.o ImageLoader.o IOManager.o PixelMtrix.o Pixel.o BinaryValFliter.o GrayFliter.o DenoiseFliter.o Fliter.o Thread.o Runnable.o Rect.o Cut.o Locate.o Cnn.o Convertion.o ConvertionKernel.o Layer.o ConvertionLayer.o PoollingLayer.o FullyConnectedLayer.o Scale.o \
	Activation.o SigMoidActivation.o
	$(CXX) -o $(BUILD_DIR)/app \
	$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/JPGImageLoader.o \
	$(OBJ_DIR)/ImageLoader.o \
	$(OBJ_DIR)/IOManager.o \
	$(OBJ_DIR)/PixelMtrix.o \
	$(OBJ_DIR)/Pixel.o \
	$(OBJ_DIR)/GrayFliter.o \
	$(OBJ_DIR)/BinaryValFliter.o \
	$(OBJ_DIR)/DenoiseFliter.o \
	$(OBJ_DIR)/Fliter.o \
	$(OBJ_DIR)/Thread.o \
	$(OBJ_DIR)/Runnable.o \
	$(OBJ_DIR)/Rect.o \
	$(OBJ_DIR)/Cut.o \
	$(OBJ_DIR)/Locate.o \
	$(OBJ_DIR)/Cnn.o \
	$(OBJ_DIR)/Convertion.o \
	$(OBJ_DIR)/ConvertionKernel.o \
	$(OBJ_DIR)/Layer.o \
	$(OBJ_DIR)/ConvertionLayer.o \
	$(OBJ_DIR)/PoollingLayer.o \
	$(OBJ_DIR)/FullyConnectedLayer.o \
	$(OBJ_DIR)/Scale.o \
	$(OBJ_DIR)/Activation.o \
	$(OBJ_DIR)/SigMoidActivation.o \
	$(LIB)
else
run:clean all
	$(BUILD_DIR)/app
all: main.o JPGImageLoader.o ImageLoader.o IOManager.o PixelMtrix.o Pixel.o Window.o WindowManager.o BinaryValFliter.o GrayFliter.o DenoiseFliter.o Fliter.o Thread.o Runnable.o Rect.o Cut.o Locate.o Cnn.o Convertion.o ConvertionKernel.o Layer.o ConvertionLayer.o PoollingLayer.o FullyConnectedLayer.o Scale.o \
	Activation.o SigMoidActivation.o
	$(CXX) -o $(BUILD_DIR)/app \
	$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/JPGImageLoader.o \
	$(OBJ_DIR)/ImageLoader.o \
	$(OBJ_DIR)/IOManager.o \
	$(OBJ_DIR)/PixelMtrix.o \
	$(OBJ_DIR)/Pixel.o \
	$(OBJ_DIR)/Window.o \
	$(OBJ_DIR)/WindowManager.o \
	$(OBJ_DIR)/GrayFliter.o \
	$(OBJ_DIR)/BinaryValFliter.o \
	$(OBJ_DIR)/DenoiseFliter.o \
	$(OBJ_DIR)/Fliter.o \
	$(OBJ_DIR)/Thread.o \
	$(OBJ_DIR)/Runnable.o \
	$(OBJ_DIR)/Rect.o \
	$(OBJ_DIR)/Cut.o \
	$(OBJ_DIR)/Locate.o \
	$(OBJ_DIR)/Cnn.o \
	$(OBJ_DIR)/Convertion.o \
	$(OBJ_DIR)/ConvertionKernel.o \
	$(OBJ_DIR)/Layer.o \
	$(OBJ_DIR)/ConvertionLayer.o \
	$(OBJ_DIR)/PoollingLayer.o \
	$(OBJ_DIR)/FullyConnectedLayer.o \
	$(OBJ_DIR)/Scale.o \
	$(OBJ_DIR)/Activation.o \
	$(OBJ_DIR)/SigMoidActivation.o \
	$(LIB)
endif

main.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/main.o -c $(BASE_DIR)/app/src/main.cpp $(LIB)

JPGImageLoader.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/JPGImageLoader.o -c $(BASE_DIR)/framework/src/io/JPGImageLoader.cpp $(LIB)
ImageLoader.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/ImageLoader.o -c $(BASE_DIR)/framework/src/io/ImageLoader.cpp $(LIB)
IOManager.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/IOManager.o -c $(BASE_DIR)/framework/src/io/IOManager.cpp $(LIB)
PixelMtrix.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/PixelMtrix.o -c $(BASE_DIR)/framework/src/image/PixelMtrix.cpp $(LIB)
Pixel.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Pixel.o -c $(BASE_DIR)/framework/src/image/Pixel.cpp $(LIB)
ifdef DEBUG

else
Window.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Window.o -c $(BASE_DIR)/framework/src/window/Window.cpp $(LIB)
WindowManager.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/WindowManager.o -c $(BASE_DIR)/framework/src/window/WindowManager.cpp $(LIB)
endif
DenoiseFliter.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/DenoiseFliter.o -c $(BASE_DIR)/framework/src/fliter/DenoiseFliter.cpp $(LIB)
Fliter.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Fliter.o -c $(BASE_DIR)/framework/src/fliter/Fliter.cpp $(LIB)
GrayFliter.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/GrayFliter.o -c $(BASE_DIR)/framework/src/fliter/GrayFliter.cpp $(LIB)
BinaryValFliter.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/BinaryValFliter.o -c $(BASE_DIR)/framework/src/fliter/BinaryValFliter.cpp $(LIB)
Thread.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Thread.o -c $(BASE_DIR)/framework/src/thread/Thread.cpp $(LIB)
Runnable.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Runnable.o -c $(BASE_DIR)/framework/src/thread/Runnable.cpp $(LIB)
Rect.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Rect.o -c $(BASE_DIR)/framework/src/image/Rect.cpp $(LIB)
Cut.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Cut.o -c $(BASE_DIR)/framework/src/cut/Cut.cpp $(LIB)
Locate.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Locate.o -c $(BASE_DIR)/framework/src/location/Locate.cpp $(LIB)
Cnn.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Cnn.o -c $(BASE_DIR)/framework/src/cnn/Cnn.cpp $(LIB)
Convertion.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Convertion.o -c $(BASE_DIR)/framework/src/cnn/Convertion.cpp $(LIB)
ConvertionKernel.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/ConvertionKernel.o -c $(BASE_DIR)/framework/src/cnn/ConvertionKernel.cpp $(LIB)
Layer.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Layer.o -c $(BASE_DIR)/framework/src/cnn/Layer.cpp $(LIB)
ConvertionLayer.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/ConvertionLayer.o -c $(BASE_DIR)/framework/src/cnn/ConvertionLayer.cpp $(LIB)
PoollingLayer.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/PoollingLayer.o -c $(BASE_DIR)/framework/src/cnn/PoollingLayer.cpp $(LIB)
FullyConnectedLayer.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/FullyConnectedLayer.o -c $(BASE_DIR)/framework/src/cnn/FullyConnectedLayer.cpp $(LIB)
Scale.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Scale.o -c $(BASE_DIR)/framework/src/scale/Scale.cpp $(LIB)
Activation.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/Activation.o -c $(BASE_DIR)/framework/src/cnn/common/Activation.cpp $(LIB)
SigMoidActivation.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJ_DIR)/SigMoidActivation.o -c $(BASE_DIR)/framework/src/cnn/common/SigMoidActivation.cpp $(LIB)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)
	mkdir $(OBJ_DIR)
	mkdir $(BUILD_DIR)


