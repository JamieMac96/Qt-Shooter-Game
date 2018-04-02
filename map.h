#include "room.h"
#include <vector>

#ifndef MAP_H
#define MAP_H


class Map{

public:
    Map(Avatar* avatar);
    // DESTRUCTOR
    ~Map();
    Room* getRoom(int index) const;
    void setRooms(vector< Room* >& rooms);
    void setCurrentRoomNumber(int number);
    void setEnemies(vector< vector < Enemy* > >&);
    void connectRooms(QPixmap doorImage,
                      unsigned int firstRoomNumber,
                      unsigned int secondRoomNumber,
                      int position);
    int size() const;
    void refresh();

private:
    bool isCleared() const;
    void moveToRoom(Door* doorSelected);
    vector< Room* > rooms;
    Avatar* avatar;
    int currentRoomNumber;

};

#endif // MAP_H
