#ifndef BULLET_H
#define BULLET_H

#include "mobileobject.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject, public MobileObject{
    Q_OBJECT

public:
    Bullet(MobileObject *parent=0);
    virtual ~Bullet(){};

private  slots:
    void move();
};

#endif // BULLET_H
