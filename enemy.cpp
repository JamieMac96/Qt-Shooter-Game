#include "enemy.h"
#include <iostream>

Enemy::Enemy(): MobileObject(1200, 700, 64, 64)
{
    spritesheet.load(":/images/wolfsheet1.png");

    sManager = new SpriteManager(spritesheet);

    spritesRequired = getSpriteSheetDescriptors();

    sManager->initializeSpriteList(spritesRequired);

    setSpeed(5);
}

int Enemy::getCurrentDirection(){
    if(movingDown)       return 0;
    else if(movingUp)    return 1;
    else if(movingRight)  return 2;
    else if(movingLeft)  return 3;
    else return currentDirection;
}

void Enemy::updateDirectionFlags(){
    if(movementCounter % 20 != 0) return;

    int direction = rand() % 5;
    movingUp = false;
    movingDown = false;
    movingRight = false;
    movingLeft = false;

    switch(direction){
        case 0:
            movingUp = true;
            break;
        case 1:
            movingDown = true;
            break;
        case 2:
            movingRight = true;
            break;
        case 3:
            movingLeft = true;
            break;
        default:
            break;
    }
}

void Enemy::updatePixmap(){
    int spriteSelected;

    if(movementCounter % 3 == 0){

        bool moving = movingRight || movingLeft || movingUp || movingDown;

        if(moving){
            // Sprite in motion
            spriteSelected = (spriteCounter % 4);
            this->currentDirection = getCurrentDirection();
        }
        else{
            // Sprite standing
            spriteSelected = 0;
            spriteCounter = 0;
        }

        this->setPixmap(sManager->getSprite(currentDirection, spriteSelected));
        spriteCounter++;
    }}

vector<SpriteSheetDescriptor> Enemy::getSpriteSheetDescriptors(){
    int numSprites = 4;
    int startYs[] = {128, 128, 96, 288};
    int startXs[] = {0, 160, 320, 320};
    int widths[] = {32, 32, 64, 64};
    int heights[] = {64, 64, 32, 32};
    vector< SpriteSheetDescriptor > descriptors;

    QPoint startPoint;
    SpriteSheetDescriptor desc;

    for(int i = 0; i < 4; i++){
        startPoint.setX(startXs[i]);
        startPoint.setY(startYs[i]);
        desc.setStartPoint(startPoint);
        desc.setSpriteHeight(heights[i]);
        desc.setSpriteWidth(widths[i]);
        desc.setNumSprites(numSprites);
        descriptors.push_back(desc);
    }

    return descriptors;
}

bool Enemy::isDead() const{
    return dead;
}

void Enemy::setDead(){
    dead = true;
}

void Enemy::refresh(){
    updateDirectionFlags();
    updatePixmap();
    move();
}
