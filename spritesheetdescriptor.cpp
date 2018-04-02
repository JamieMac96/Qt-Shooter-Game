#include "spritesheetdescriptor.h"

SpriteSheetDescriptor::SpriteSheetDescriptor(){
    spriteWidth = 0;
    spriteHeight = 0;
    numSprites = 0;
}

SpriteSheetDescriptor::SpriteSheetDescriptor(QPoint point, int width, int height, int numEls){
    startPoint = point;
    spriteWidth = width;
    spriteHeight = height;
    numSprites = numEls;
}

void SpriteSheetDescriptor::setStartPoint(QPoint point){
    startPoint = point;
}

void SpriteSheetDescriptor::setStartPoint(int x, int y){
    startPoint.setX(x);
    startPoint.setY(y);
}

void SpriteSheetDescriptor::setSpriteWidth(int width){
    spriteWidth = width;
}

void SpriteSheetDescriptor::setSpriteHeight(int height){
    spriteHeight = height;
}

void SpriteSheetDescriptor::setNumSprites(int numEls){
    numSprites = numEls;
}

QPoint SpriteSheetDescriptor::getStartPoint() const{
    return startPoint;
}

int SpriteSheetDescriptor::getSpriteWidth() const{
    return spriteWidth;
}

int SpriteSheetDescriptor::getSpriteHeight() const{
    return spriteHeight;
}

int SpriteSheetDescriptor::getNumSprites() const{
    return numSprites;
}
