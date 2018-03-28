#include "room.h"
#include <vector>

#ifndef MAP_H
#define MAP_H


class Map
{

public:
    Map(int maxX, int maxY, Avatar* avatar);
    ~Map();
    Room* getRoom(int index);
    void addRooms(vector< Room* > rooms);
    void setCurrentRoomNumber(int number);
    int size();
    void refresh();

private:
    bool isCleared();
    void moveToRoom(Door* doorSelected);
    QPoint getNewAvatarPosition(QPoint oldPosition);
    vector< Room* > rooms;
    Avatar* avatar;
    int currentRoomNumber;
    int maxX;
    int maxY;

};

#endif // MAP_H
