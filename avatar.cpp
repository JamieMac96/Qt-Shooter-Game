#include "avatar.h"
#include "stdio.h"
#include "mobileobject.h"
#include "bullet.h"
#include <iostream>
#include <QDebug>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>

using namespace std;

Avatar::Avatar(): MobileObject(940, 500){

    //TODO: Refactor into logical inheritance hierarchy
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    width = 120;
    height = 120;
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

void Avatar::keyReleaseEvent(QKeyEvent *event)
{
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

void Avatar::refresh(){
    this->move();
    this->updatePixmap();
}

// This member function retrieves the position of the gun
// held by the avatar
// It is calculated based on the direction that the avatar
// is facing (note that is only correct for the spritesheet
// specific being used)
QPoint Avatar::getGunPosition(){
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

    cout << "position " << x << ", " << y << endl;
    cout << "width" << width << endl;
    cout << "height" << height << endl;

    return QPoint(x, y);
}
