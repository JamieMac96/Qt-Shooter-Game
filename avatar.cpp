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
    if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet(this);
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
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
}
