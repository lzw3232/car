#include <iostream>
#include "../../framework/include/io/JPGImageLoader.h"
#include "../../framework/include/fliter/GrayFliter.h"
#include "../../framework/include/fliter/BinaryValFliter.h"
#include "../../framework/include/window/Window.h"
#include "../../framework/include/window/WindowManager.h"
#include "../../framework/include/fliter/DenoiseFliter.h"
#include "../../framework/include/cut/Cut.h"
#include "../../framework/include/location/Locate.h"
#include "../../framework/include/cnn/ConvertionKernel.h"
#include "../../framework/include/cnn/Cnn.h"
#include "../../framework/include/scale/Scale.h"
#include <vector>

int main(int argc,char *argv[]){
    
    lzw::ImageLoader *jpgLoader = new lzw::JPGImageLoader();
    //lzw::PixelMtrix *pixels1 = jpgLoader->loadImage("/home/lzw/study/car/img/1.jpg");
    //lzw::PixelMtrix *pixels2 = jpgLoader->loadImage("/home/lzw/study/car/img/1.jpg");
    lzw::PixelMtrix *pixels3 = jpgLoader->loadImage("/home/lzw/study/car/img/1.jpg");
    //std::cout<<pixels->getWidth()<<std::endl;
    //std::cout<<pixels->getHeight()<<std::endl;
    lzw::Window *defaultWindow=new lzw::Window(pixels3->getWidth(),pixels3->getHeight(),"IMG");
    defaultWindow->SetPixelMtrix(pixels3);

    lzw::Locate *locate = new lzw::Locate(pixels3);
    pixels3 = locate->doLocate();
    lzw::Window *locateWindow=new lzw::Window(pixels3->getWidth(),pixels3->getHeight(),"定位");
    locateWindow->SetPixelMtrix(locate->doLocate());


    //lzw::Window *GrayWindow=new lzw::Window(pixels1->getWidth(),pixels1->getHeight(),"灰度化");
    //lzw::Fliter *grayFliter = new lzw::GrayFliter(pixels);
    //lzw::Fliter *GrayFliter = new lzw::GrayFliter(pixels1);
    //GrayWindow->SetPixelMtrix(GrayFliter->doFliter());

    lzw::Window *BinaryWindow=new lzw::Window(pixels3->getWidth(),pixels3->getHeight(),"二值化");
    lzw::Fliter *binaryValFliter = new lzw::BinaryValFliter(pixels3);
    BinaryWindow->SetPixelMtrix(binaryValFliter->doFliter());



    lzw::Window *denoiseWindow=new lzw::Window(pixels3->getWidth(),pixels3->getHeight(),"去噪");
    lzw::Fliter *denoiseFliter = new lzw::DenoiseFliter(binaryValFliter->doFliter());
    denoiseWindow->SetPixelMtrix(denoiseFliter->doFliter());


    lzw::Cut *cut = new lzw::Cut(pixels3);
    cut->doCut();
    std::vector<lzw::Window *> windows;

    for(int i=0;i<cut->getArray().size();i++){
        lzw::PixelMtrix *pixels4 = cut->clip(pixels3,cut->getArray().at(i));
        lzw::Window *cutWindow_piece = new lzw::Window(pixels4->getWidth()+30,pixels4->getHeight(),"切1");
        cutWindow_piece->SetPixelMtrix(pixels4);
        windows.push_back(cutWindow_piece);
    }
    lzw::PixelMtrix *pixels4 = cut->clip(pixels3,cut->getArray().at(2));
    std::cout<<pixels4->getWidth()<<" "<<pixels4->getHeight()<<std::endl;

    lzw::cnn::CNN *cnn = new lzw::cnn::CNN();
    
    lzw::Window *Window4 = new lzw::Window(pixels4->getWidth(),pixels4->getHeight(),"4");
    Window4->SetPixelMtrix(pixels4);

    lzw::Scale *scale = new lzw::Scale(64,64,pixels4);
    lzw::PixelMtrix *pixels5 = scale->doScale();

    lzw::Window *Window5 = new lzw::Window(pixels5->getWidth(),pixels5->getHeight(),"4");
    Window5->SetPixelMtrix(pixels5);

    std::vector<lzw::PixelMtrix *> picture;
    picture.push_back(pixels4);

    lzw::Vector *v = new lzw::Vector(3,3);
    std::vector<lzw::Vector *> vs;
    vs.push_back(v);

    lzw::cnn::ConvertionKernel *kernel = new lzw::cnn::ConvertionKernel();
    lzw::cnn::ConvertionLayer *layer = new lzw::cnn::ConvertionLayer(23,36,1,picture,kernel);
    cnn->input(layer,1,1,1,lzw::cnn::KernelGenerateMode::RANDOM,vs);
    cnn->train();
    

    lzw::WindowManager *manager=lzw::WindowManager::GetWindowManagerInstance();



    // for(int rows=0; rows<pixels2->getHeight();rows++){
    //     for(int cols=0; cols<pixels2->getWidth();cols++){
    //         std::cout<<pixels2->getPixel()[rows][cols].getColor()->getR()<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    // manager->createWindow(defaultWindow);
    // manager->createWindow(locateWindow);
    // //manager->createWindow(GrayWindow);
    // manager->createWindow(BinaryWindow);
    //  manager->createWindow(denoiseWindow);
    // for(int i = 0;i<cut->getArray().size();i++){ 
    //     manager->createWindow(windows.at(i));
    // }

    manager->createWindow(Window4);
    manager->createWindow(Window5);
    manager->renderWindow();
    
    return 0;

}