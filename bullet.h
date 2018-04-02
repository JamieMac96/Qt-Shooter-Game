#ifndef BULLET_H
#define BULLET_H

#include "mobileitem.h"
#include "collidableitem.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

// INHERITANCE
class Bullet: public QObject, public MobileItem, public CollidableItem{
    Q_OBJECT

public:
    Bullet(MobileItem *parent=0);
    bool handleCollision();
    void move();

public  slots:
    void refresh();

private:
};

#endif // BULLET_H
