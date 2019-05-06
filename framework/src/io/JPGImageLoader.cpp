#include "../../include/io/JPGImageLoader.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace lzw;

JPGImageLoader::JPGImageLoader():ImageLoader(ImageFormat::JPG){
}

JPGImageLoader::~JPGImageLoader(){

}

void JPGImageLoader::write_pixel_data(j_decompress_ptr cinfo, unsigned char *output_buffer)  
 {
        this->getPixelMtrix()->setWidth(cinfo->output_width);
        this->getPixelMtrix()->setHeight(cinfo->output_height);
        this->getPixelMtrix()->setData(cinfo->num_components,output_buffer);
 }  
  
  
 /*读JPEG文件相当于解压文件*/  
  
 int JPGImageLoader::read_jpeg_file(const char *input_filename)  
 {  
        struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	JSAMPROW row_pointer[1];
	
	FILE *infile = fopen( input_filename, "rb" );
	unsigned long location = 0;
	int i = 0;
	
	if ( !infile )
	{
		printf("Error opening jpeg file %s\n!", input_filename );
		return -1;
	}

	cinfo.err = jpeg_std_error( &jerr );

	jpeg_create_decompress( &cinfo );

	jpeg_stdio_src( &cinfo, infile );

	jpeg_read_header( &cinfo, TRUE );

	jpeg_start_decompress( &cinfo );
	printf("components = %d \n", cinfo.num_components);

	unsigned char *raw_image = (unsigned char*)malloc( cinfo.output_width*cinfo.output_height*cinfo.num_components );

	row_pointer[0] = (unsigned char *)malloc( cinfo.output_width*cinfo.num_components );

	while( cinfo.output_scanline < cinfo.image_height )
	{
		jpeg_read_scanlines( &cinfo, row_pointer, 1 );
		for( i=0; i<cinfo.image_width*cinfo.num_components;i++) 
			raw_image[location++] = row_pointer[0][i];
	}

	write_pixel_data(&cinfo,raw_image);

	jpeg_finish_decompress( &cinfo );
	jpeg_destroy_decompress( &cinfo );
	free(row_pointer[0] );
	fclose( infile );

	return 1;
 } 
 

PixelMtrix *JPGImageLoader::loadImage(const char *imgPath){
    this->setPixelMtrix(new PixelMtrix());
    //this->getIO()->loadFile(imgPath);
    //std::cout<<this->getIO()->getBufferSize()<<std::endl;


    this->read_jpeg_file(imgPath);

    // for(int i=0;i<this->getIO()->getBufferSize();i++){
    //     std::cout<<" 0x"<<std::hex<<(0xFF & this->getIO()->getBuffer()[i]);
    //     if(i%8 == 0){
    //         std::cout<<std::endl;
    //     }
    // }
    
    return this->getPixelMtrix();

}