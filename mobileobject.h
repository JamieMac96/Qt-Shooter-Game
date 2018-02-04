#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QGraphicsRectItem>

class MobileObject: public QGraphicsRectItem
{
public:
    MobileObject();
    virtual void move() = 0;
};

#endif // MOVABLEOBJECT_H
