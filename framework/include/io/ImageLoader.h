#ifndef __FRAMEWORK_IMAGELOADER_H__
#define __FRAMEWORK_IMAGELOADER_H__

#include "../../include/image/PixelMtrix.h"
#include "../../include/io/IOManager.h"

namespace lzw{

    typedef enum ImageFormat{
        PNG,
        JPG,
        JPGE,
        BMP,
    }ImageFormat;

    class ImageLoader
    {
        private:
            /* data */
            IOManager *io;
            PixelMtrix *pixels;

        public:
            ImageLoader(ImageFormat format);

            virtual PixelMtrix *loadImage(const char *imgPath) = 0;
            IOManager *getIO(){return this->io;};
            PixelMtrix *getPixelMtrix(){return this->pixels;};

            void setPixelMtrix(PixelMtrix *pixels){this->pixels=pixels;};

            ~ImageLoader();
        };
};

#endif //!__FRAMEWORK_IMAGELOADER_H__