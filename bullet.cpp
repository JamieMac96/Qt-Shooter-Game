#include "bullet.h"
#include "enemy.h"
#include "gameconstants.h"
#include <QTimer>
#include <QGraphicsScene>
#include <iostream>
#include <typeinfo>

using namespace std;

Bullet::Bullet(MobileItem *parent): QObject(),
        MobileItem(maximumX - 10, maximumY - 10, 6, 8){
    setPixmap(QPixmap(":images/bullet.png"));
    setSpeed(10);

    // The bullet will take on the directional properties
    // of the mobileObject that fired it
    currentDirection = parent->getCurrentDirection();
    this->setMovementFlags(currentDirection);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(refresh()));

    // start the timer.
    timer->start(10);
}

void Bullet::refresh()
{
    if(!handleCollision()) move();
}

bool Bullet::handleCollision()
{
    // Check for collision
    QList< QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*colliding_items[i]) == typeid(Enemy)){
            Enemy *enemy = dynamic_cast< Enemy* >(colliding_items[i]);
            enemy->setDead();
            scene()->removeItem(enemy);
            scene()->removeItem(this);
            delete this;
            return true;
        }
    }
    return false;
}


void Bullet::move(){

    // If there is no collision we move the bullet
    MobileItem::move();

    // if the bullet is off the screen, destroy it
    bool offScreen  = (pos().x() <= 0 || pos().y() <= 0
                       || pos().x() >= maxX - 10 || pos().y() >= maxY - 10);

    if(offScreen){
        scene()->removeItem(this);
        delete this;
    }
}
