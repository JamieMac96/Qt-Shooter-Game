#include "avatar.h"
#include "enemy.h"
#include "door.h"
#include <QGraphicsScene>

#ifndef ROOM_H
#define ROOM_H


class Room
{

public:
    Room(int id, QGraphicsScene *scene, int maxX, int maxY);
    ~Room();
    vector< Door* > getDoors();
    QPoint getRightDoorPosition();
    QPoint getLeftDoorPosition();
    QPoint getTopDoorPosition();
    QPoint getBottomDoorPosition();
    QPoint getNewAvatarPosition(QPoint oldPosition);
    void addItemsToScene();
    void removeItemsFromScene();
    void addDoor(Door* door);
    void setEnemies(vector< Enemy* > enemies);
    void refresh();
    bool isCleared();

private:
    QGraphicsScene *scene;
    vector< Enemy *> enemies;
    vector< Door* > doors;
    int id;
    int maxX;
    int maxY;
};

#endif // ROOM_H
