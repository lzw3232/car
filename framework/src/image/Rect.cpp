#include "../../include/image/Rect.h"

using namespace lzw;

Rect::Rect(int posX, int posY)
{
    this->posX=posX;
    this->posY=posY;
    this->width=posY-posX;
}

Rect::~Rect()
{
}