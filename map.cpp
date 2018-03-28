#include "map.h"
#include <iostream>

Map::Map(int maxX, int maxY, Avatar* avatar)
{
    this->maxX = maxX;
    this->maxY = maxY;
    this->avatar = avatar;
}

Map::~Map()
{

}

Room* Map::getRoom(int index){
    return rooms.at(index);
}

void Map::addRooms(vector<Room *> roomList){
    rooms.insert(rooms.end(), roomList.begin(), roomList.end());
}

void Map::setCurrentRoomNumber(int number){
    this->currentRoomNumber = number;
}


void Map::refresh(){
    Room *currentRoom = rooms.at(this->currentRoomNumber);
    vector< Door* > doors = currentRoom->getDoors();

    currentRoom->refresh();

    for(int i = 0; i < doors.size(); i++){
        Door *currentDoor = doors.at(i);
        if(currentDoor->collisionOccured()){
            moveToRoom(currentDoor);
        }
    }
}

void Map::moveToRoom(Door* doorSelected){
    rooms.at(this->currentRoomNumber)->removeItemsFromScene();
    this->currentRoomNumber = doorSelected->getRoomLink();
    rooms.at(currentRoomNumber)->addItemsToScene();

    QPoint newPos = getNewAvatarPosition(doorSelected->getPosition());
    avatar->setPos(newPos);
}

int Map::size(){
    return rooms.size();
}

bool Map::isCleared(){
    for(int i = 0; i < rooms.size(); i++){
        if(!rooms.at(i)->isCleared()){
            return false;
        }
    }

    return true;
}

// Based on the point at which the avatar left the old
// room we calculate the point they will enter the new room.
QPoint Map::getNewAvatarPosition(QPoint oldPosition){
    QPoint newPosition;

    int oldX = oldPosition.x();
    int oldY = oldPosition.y();
    int newX = 0;
    int newY = 0;

    if(oldX == 0){
        newX = maxX - 100;
    }
    else if(oldX == maxX - 50){
        newX = 100;
    }
    else{
        newX = oldX;
    }
    if(oldY == 0){
        newY = maxY - 250;
    }
    else if(oldY == maxY - 150){
        newY = 120;
    }
    else{
        newY = oldY;
    }

    newPosition.setX(newX);
    newPosition.setY(newY);

    return newPosition;
}
