#include "mobileobject.h"
#include "animatedobject.h"
#include <string>
#include <iostream>

using namespace std;


MobileObject::MobileObject(int maxX, int maxY) : AnimatedObject(":/images/cowboy.png", 120, 130){
    this->movingUp = false;
    this->movingDown = false;
    this->movingRight = false;
    this->movingLeft = false;
    this->maxX = maxX;
    this->maxY = maxY;
    this->spriteSpacingHorizontal = 129;
    this->spriteSpacingVertical = 129;
    this->movementCounter = 0;
    this->spriteCounter = 0;
    this->initializeSpriteVectors();
    this->currentDirection = 3;
}

void MobileObject::move(){
    movementCounter++;

    updatePixmap();

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
    // 2 --> Down Right
    // 3 --> Right
    // 4 --> Up Right
    // 5 --> Up
    // 6 --> Up Left
    // 7 --> Left
    // 8 --> Down Left
    // 9 --> Down

    if(movementCounter % 3 == 0){

        int spriteSelected;
        bool moving = movingRight || movingLeft || movingUp || movingDown;

        if(moving){
            // Sprite in motion
            spriteSelected = spriteCounter % 9 + 1;

            if(movingRight && movingDown)      currentDirection = 2;
            else if(movingRight && movingUp)   currentDirection = 4;
            else if(movingLeft && movingUp)    currentDirection = 6;
            else if(movingLeft && movingDown)  currentDirection = 8;
            else if(movingRight)               currentDirection = 3;
            else if(movingUp)                  currentDirection = 5;
            else if(movingLeft)                currentDirection = 7;
            else if(movingDown)                currentDirection = 9;
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
    int currentHeight = 0;

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
