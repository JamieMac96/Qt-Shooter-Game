#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <iostream>

using namespace std;

Bullet::Bullet(MobileObject *parent): QObject(),  MobileObject(940, 500){
    this->setPixmap(QPixmap(":images/bullet.png"));

    // The bullet will take on the directional properties
    // of the mobileObject that fired it
    currentDirection = parent->getCurrentDirection();
    this->setMovementFlags(currentDirection);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}


void Bullet::move(){
    MobileObject::move();
    // if the bullet is off the screen, destroy it
    bool offScreen  = (pos().x() <= 0 || pos().y() <= 0
                       || pos().x() >= maxX || pos().y() >= maxY);

    if(offScreen){
        scene()->removeItem(this);
        delete this;
    }
}
