#include "mobileobject.h"
#include "animatedobject.h"
#include <string>
#include <iostream>

using namespace std;


MobileObject::MobileObject(int maxX, int maxY) : AnimatedObject(":/images/cowboy.png", 129, 129){
    this->movingUp = false;
    this->movingDown = false;
    this->movingRight = false;
    this->movingLeft = false;
    this->shooting = false;
    this->maxX = maxX;
    this->maxY = maxY;
    this->spriteSpacingHorizontal = 128;
    this->spriteSpacingVertical = 129;
    this->movementCounter = 0;
    this->spriteCounter = 0;
    this->initializeSpriteVectors();
    this->currentDirection = 3;
}

void MobileObject::move(){
    movementCounter++;

    if(movingUp){
        this->moveUp();
    }
    if(movingDown){
        this->moveDown();
    }
    if(movingRight){
        this->moveRight();
    }
    if(movingLeft){
        this->moveLeft();
    }
}

void MobileObject::updatePixmap(){
    int spriteSelected;

    if(shooting){
        spriteSelected = 11;
        this->setPixmap(spriteList.at(currentDirection).at(spriteSelected));
    }

    else if(movementCounter % 3 == 0){

        bool moving = movingRight || movingLeft || movingUp || movingDown;

        if(moving){
            // Sprite in motion
            spriteSelected = (spriteCounter % 9) + 1;
            this->currentDirection = getCurrentDirection();
        }
        else{
            // Sprite standing
            spriteSelected = 0;
            spriteCounter = 0;
        }

        this->setPixmap(spriteList.at(currentDirection).at(spriteSelected));
        spriteCounter++;
    }
}

void MobileObject::moveUp(){
    int nextY = ((((this->y() - 10)) < 0) ? 0 : (this->y() - 10));
    this->setPos(this->x(), nextY);
}

void MobileObject::moveDown(){
    int nextY = ((this->y() + 10) > this->maxY) ? this->y(): this->y() + 10;
    this->setPos(this->x(), nextY);
}

void MobileObject::moveRight(){
    int nextX = ((((this->x() + 10)) > this->maxX) ? this->x() : (this->x() + 10));
    this->setPos(nextX, this->y());
}

void MobileObject::moveLeft(){
    int nextX = ((((this->x() - 10)) < 0) ? 0 : (this->x() - 10));
    this->setPos(nextX, this->y());
}

void MobileObject::initializeSpriteVectors(){
    int maxWidth = this->spritesheet->width();
    int maxHeight = this->spritesheet->height();
    int currentWidth = 0;

    // In this case the first row of sprites that we want is the
    // second 3rd row
    int currentHeight = 2 * spriteSpacingVertical;

    for(int i = 0; currentHeight < maxHeight; i++){
        vector<QPixmap> currentRow;
        while(currentWidth < maxWidth){
            QImage currentImage = spritesheet->copy(currentWidth, currentHeight, width, height);
            QPixmap nextPixmap = QPixmap::fromImage(currentImage);
            currentRow.push_back(nextPixmap);
            currentWidth += spriteSpacingHorizontal;
        }
        spriteList.push_back(currentRow);
        currentRow.clear();
        currentHeight += spriteSpacingVertical;
        currentWidth = 0;
    }
}

int MobileObject::getCurrentDirection(){
    if(movingRight && movingDown)      return 0;
    else if(movingRight && movingUp)   return 2;
    else if(movingLeft && movingUp)    return 4;
    else if(movingLeft && movingDown)  return 6;
    else if(movingRight)               return 1;
    else if(movingUp)                  return 3;
    else if(movingLeft)                return 5;
    else if(movingDown)                return 7;
    else return currentDirection;
}

void MobileObject::setMovementFlags(int direction){
    movingRight = false;
    movingLeft = false;
    movingUp = false;
    movingDown = false;

    if(direction == 0){
        movingRight = true;
        movingDown = true;
    }
    else if(direction == 1){
        movingRight = true;
    }
    else if(direction == 2){
        movingRight = true;
        movingUp = true;
    }
    else if(direction == 3){
        movingUp = true;
    }
    else if(direction == 4){
        movingLeft = true;
        movingUp = true;
    }
    else if(direction == 5){
        movingLeft = true;
    }
    else if(direction == 6){
        movingLeft = true;
        movingDown = true;
    }
    else if(direction == 7){
        movingDown = true;
    }
}
