#ifndef __FRAMEWORK_PIXELMTRIX_H__
#define __FRAMEWORK_PIXELMTRIX_H__

#include "../../include/image/Pixel.h"
#include "../../include/image/Rect.h"

namespace lzw{

    class PixelMtrix{
        private:
            /* data */
            int height;
            int width;
            Pixel **pixels;//image data

        public:
            
            PixelMtrix(/* args */);
            PixelMtrix(int width,int height);
            ~PixelMtrix();

            void setWidth(int width){this->width=width;};
            void setHeight(int height){this->height=height;};
            void setData(int num_components, unsigned char *buffer);

            int getWidth(){return this->width;};
            int getHeight(){return this->height;};
            Pixel **getPixel(){return this->pixels;};
            void setPixels(Pixel** pixels){ this->pixels=pixels;};
            void setPixel(int rows,int cols,Pixel *pixel){this->pixels[rows][cols]=*pixel;};

    };
};

#endif //! __FRAMEWORK_PIXELMTRIX_H__

