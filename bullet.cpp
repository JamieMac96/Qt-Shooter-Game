#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <iostream>

using namespace std;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    this->setPixmap(QPixmap(":images/bullet.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}


void Bullet::move(){
    setPos(x(),y()-10);

       // if the bullet is off the screen, destroy it

    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
