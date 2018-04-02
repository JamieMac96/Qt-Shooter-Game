#include "avatar.h"
#include "stdio.h"
#include "mobileitem.h"
#include "bullet.h"
#include "enemy.h"
#include "gameconstants.h"
#include <iostream>
#include <QDebug>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <typeinfo>

using namespace std;


Avatar::Avatar(): MobileItem(maximumX, maximumY, avatarHeight, avatarWidth){
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    healthBar = new HealthBar(3);

    spritesheet.load(":images/cowboy.png");
    sManager = new SpriteManager(spritesheet);
    spritesRequired = getSpriteSheetDescriptors();
    sManager->initializeSpriteList(spritesRequired);

}

Avatar::~Avatar(){
    delete sManager;
    delete healthBar;
}

void Avatar::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up){
        this->movingUp = true;
    }
    if(event->key() == Qt::Key_Down){
        this->movingDown = true;
    }
    if(event->key() == Qt::Key_Right){
        this->movingRight = true;
    }
    if(event->key() == Qt::Key_Left){
        this->movingLeft = true;
    }
    if(event->key() == Qt::Key_Space && !event->isAutoRepeat()){
        Bullet *bullet = new Bullet(this);
        bullet->setPos(getGunPosition());
        scene()->addItem(bullet);

        this->shooting = true;
    }
}

void Avatar::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up){
        this->movingUp = false;
    }
    if(event->key() == Qt::Key_Down){
        this->movingDown = false;
    }
    if(event->key() == Qt::Key_Right){
        this->movingRight = false;
    }
    if(event->key() == Qt::Key_Left){
        this->movingLeft = false;
    }
    if(event->key() == Qt::Key_Space){
        this->shooting = false;
    }
}

bool Avatar::handleCollision(){
    if(movementCounter % 10 != 0) return false;

    QList< QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*colliding_items[i]) == typeid(Enemy)){
            // Avatar reacts to damage received
            setPixmap(sManager->getSprite(currentDirection, 12));
            (*healthBar)--;
            return true;
        }
    }
    return false;
}
void Avatar::updatePixmap(){
    int spriteSelected;

    if(shooting){
        spriteSelected = 11;
        setPixmap(sManager->getSprite(currentDirection, spriteSelected));
    }
    else if(movementCounter % 4 == 0){

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

        this->setPixmap(sManager->getSprite(currentDirection, spriteSelected));
        spriteCounter++;
    }
}


void Avatar::refresh(){
    handleCollision();
    move();
    updatePixmap();
}


bool Avatar::isDead() const{
    return healthBar->getHealth() <= 0;
}

HealthBar* Avatar::getHealthBar(){
    return healthBar;
}

// This member function retrieves the position of the gun
// held by the avatar
// It is calculated based on the direction that the avatar
// is facing (note that it is only correct for the specific
// spritesheet being used)
QPoint Avatar::getGunPosition() const{
    int x = this->x();
    int y = this->y();
    switch (currentDirection) {
    case 0:
        x += width - 20;
        y += height - 30;
        break;
    case 1:
        x += width;
        y += height / 2 - 10;
        break;
    case 2:
        x += width - 10;
        y += 25;
        break;
    case 3:
        x += width / 2 + 20;
        break;
    case 4:
        x += 10;
        y += 10;
        break;
    case 5:
        y += height / 2  - 30;
        x -= 30;
        break;
    case 6:
        y += height - 40;
        x -= 20;
        break;
    case 7:
        x += width / 4;
        y += height;
        break;
    default:
        break;
    }

    return QPoint(x, y);
}

// This method returns a vector of SpriteSheetDescriptors which
// can then be used by the SpriteManager to correctly read the required
// sprites.
vector< SpriteSheetDescriptor > Avatar::getSpriteSheetDescriptors(){
    int currentHeight = 2*height;
    int numSprites = 14;
    int maxHeight = spritesheet.height();
    vector< SpriteSheetDescriptor > descriptors;

    while(currentHeight < maxHeight){
        QPoint startPoint(0, currentHeight);
        SpriteSheetDescriptor currentDesc(startPoint, width, height, numSprites);

        descriptors.push_back(currentDesc);
        currentHeight += height;
    }

    return descriptors;
}

