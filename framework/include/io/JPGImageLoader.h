#ifndef __FRAMEWORK_JPG_IMAGELOADER_H__
#define __FRAMEWORK_JPG_IMAGELOADER_H__

#include "../../include/io/ImageLoader.h"
#include<iostream>
// #define JCONFIG_INCLUDED
// #define JPEG_LIB_VERSION 80
// #define LIBJPEG_TURBO_VERSION 1.4.2
// #define C_ARITH_CODING_SUPPORTED 1
// #define D_ARITH_CODING_SUPPORTED 1
// #define BITS_IN_JSAMPLE  8  
// #define HAVE_UNSIGNED_CHAR 1
// #define HAVE_UNSIGNED_SHORT 1
// #define NEED_SYS_TYPES_H 1
// #define WITH_SIMD 1
// #ifndef __CHAR_UNSIGNED__
// #endif
// #define SIZEOF_SIZE_T 8

extern "C"{
    #include "jpeglib.h"
}

namespace lzw{

    typedef enum SegmentType{
        SOI=0xD8,    //D8     文件头
        EOI=0xD9,    //D9     文件尾
        SOF0=0xC0,   //C0     帧开始（标准 JPEG）
        SOF1=0xC1,   //C1     同上
        DHT=0xC4,    //C4     定义 Huffman 表（霍夫曼表）
        SOS=0xDA,    //DA     扫描行开始
        DQT=0xDB,    //DB     定义量化表
        DRI=0xD0,    //DD     定义重新开始间隔
        APP0=0xE0,   //E0     定义交换格式和图像识别信息
        COM=0xFE,    //FE     注释
    }SegmentType;

    typedef struct SOI{
        char segFlag;
        char segType;
    }JPG_SOI_T;


    typedef struct EOI{
        char segFlag;
        char segType;
    }JPG_EOI_T;


    typedef struct APP0{
        char segFlag;
        char segType;
    }JPG_APP0_T;

    typedef struct JPEG{

    }JPEG_T;

    class JPGImageLoader:public ImageLoader
    {
        private:
            /* data */
            void write_pixel_data(j_decompress_ptr cinfo, unsigned char *output_buffer);
            int read_jpeg_file(const char *input_filename);
        public:
            JPGImageLoader();
            PixelMtrix *loadImage(const char *imgPath);
            ~JPGImageLoader();
    };
        
};

#endif //!__FRAMEWORK_JPG_IMAGELOADER_H__