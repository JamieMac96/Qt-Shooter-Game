#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsPixmapItem>
#include "collidableitem.h"

class Door: public QGraphicsPixmapItem, public CollidableItem{

public:
    Door(int roomLink, QPixmap pixmap, QPoint position);
    int getRoomLink() const;
    QPoint getPosition() const;
    bool handleCollision();

private:
    int roomLink;
    QPoint position;

};

#endif // DOOR_H
