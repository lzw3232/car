#ifndef __FRAMEWORK_PIXEL_H__
#define __FRAMEWORK_PIXEL_H__

namespace lzw{
    
    typedef unsigned int ui32;
    class Color{
        private:
            ui32 color;
        public:
        Color(ui32 r, ui32 g, ui32 b);
        Color(ui32 r, ui32 g, ui32 b, ui32 alpha);
        ~Color();

        ui32 setR(ui32 r);
        ui32 setG(ui32 g);
        ui32 setB(ui32 b);
        ui32 setAlpha(ui32 alpha);

        ui32 getR();
        ui32 getG();
        ui32 getB();
        ui32 getAlpha();

        ui32 getGray();
        ui32 getBinaryVal();
    };
    

    class Pixel
    {
    private:
        /* data */
        Color *color;
    public:
        Pixel(/* args */);
        ~Pixel();
        Pixel(Color *color);
        Pixel(ui32 r, ui32 g, ui32 b);
        Pixel(ui32 r, ui32 g, ui32 b, ui32 alpha);

        Color *getColor(){return this->color;};
        void setColor(Color *color){this->color=color;};
    };
    

    
}

#endif //! __FRAMEWORK_PIXEL_H__