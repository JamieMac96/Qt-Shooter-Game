#include "avatar.h"
#include "enemy.h"
#include "door.h"
#include <QGraphicsScene>

#ifndef ROOM_H
#define ROOM_H


class Room{

public:
    Room(int id, QGraphicsScene *scene, int maxX, int maxY);
    ~Room();
    vector< Door* > getDoors() const;
    QPoint getRightDoorPosition() const;
    QPoint getLeftDoorPosition() const;
    QPoint getTopDoorPosition() const;
    QPoint getBottomDoorPosition() const;
    QPoint getDoorPosition(int position) const;
    QPoint getNewAvatarPosition(QPoint oldPosition) const;
    vector< Enemy* > getEnemies() const;
    void setEnemies(vector< Enemy* >& enemies);
    void addDoor(Door* door);
    void addItemsToScene();
    void removeItemsFromScene();
    void refresh();
    bool isCleared();

private:
    QGraphicsScene *scene;
    vector< Enemy* > enemies;
    vector< Door* > doors;
    int id;
    int maxX;
    int maxY;
};

#endif // ROOM_H
