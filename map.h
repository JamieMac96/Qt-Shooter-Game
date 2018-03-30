#include "room.h"
#include <vector>

#ifndef MAP_H
#define MAP_H


class Map
{

public:
    Map(Avatar* avatar);
    ~Map();
    Room* getRoom(int index);
    void setRooms(vector< Room* > rooms);
    void setCurrentRoomNumber(int number);
    void setEnemies(vector< vector < Enemy* > >);
    int size();
    void refresh();

private:
    bool isCleared();
    void moveToRoom(Door* doorSelected);
    vector< Room* > rooms;
    Avatar* avatar;
    int currentRoomNumber;
    int maxX;
    int maxY;

};

#endif // MAP_H
