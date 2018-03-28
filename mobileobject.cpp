#include "mobileobject.h"
#include "spritesheetdescriptor.h"
#include <string>
#include <iostream>

using namespace std;


MobileObject::MobileObject(int maxX, int maxY, int height, int width){
    this->movingUp = false;
    this->movingDown = false;
    this->movingRight = false;
    this->movingLeft = false;
    this->shooting = false;
    this->maxX = maxX;
    this->maxY = maxY;
    this->height = height;
    this->width = width;
    this->movementCounter = 0;
    this->spriteCounter = 0;
    this->currentDirection = 3;
    this->speed = 10;
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

void MobileObject::setSpeed(int speed){
    this->speed = speed;
}

void MobileObject::moveUp(){
    int nextY = ((((this->y() - speed)) < 0) ? 0 : (this->y() - speed));
    this->setPos(this->x(), nextY);
}

void MobileObject::moveDown(){
    int qualifiedY = this->y() + height;

    int nextY = (qualifiedY > maxY) ? this->y(): this->y() + speed;
    this->setPos(this->x(), nextY);
}

void MobileObject::moveRight(){
    int qualifiedX = this->x() + width;

    int nextX = (qualifiedX > maxX) ? this->x() : (this->x() + speed);
    this->setPos(nextX, this->y());
}

void MobileObject::moveLeft(){
    int nextX = ((((this->x() - speed)) < 0) ? 0 : (this->x() - speed));
    this->setPos(nextX, this->y());
}


