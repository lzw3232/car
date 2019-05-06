#ifndef __FRAMEWORK_RECT_H__
#define __FRAMEWORK_RECT_H__

namespace lzw{

    class Rect
    {
    private:
        /* data */
        int posX;
        int posY;
        int width;
        int height;
    public:
        Rect(int posX, int posY);
        ~Rect();
        int getPosX(){return this->posX;};
        int getPosY(){return this->posY;};
        void setHeight(int height){this->height=height;};
        int getWidth(){return this->width;};
        int getHeight(){return this->height;};
    };
    
    
};

#endif //! __FRAMEWORK_RECT_H__

