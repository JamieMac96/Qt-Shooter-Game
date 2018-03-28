#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsPixmapItem>

class Door: public QGraphicsPixmapItem
{

public:
    Door(int roomLink, QPixmap pixmap, QPoint position);
    int getRoomLink() const;
    QPoint getPosition() const;
    bool collisionOccured();

private:
    int roomLink;
    QPoint position;

};

#endif // DOOR_H
