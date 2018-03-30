#include "map.h"
#include <iostream>

Map::Map(Avatar* avatar)
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

void Map::setRooms(vector<Room *> roomList){
    rooms = roomList;
}

void Map::setCurrentRoomNumber(int number){
    this->currentRoomNumber = number;
}

void Map::setEnemies(vector<vector<Enemy *> > enemies)
{
    // if enmies.size() == rooms.size() then there
    //will be a list of enemies for each room
    int loopCondition = min(enemies.size(), rooms.size());

    for(int i = 0; i < loopCondition; i++){
        this->rooms.at(i)->setEnemies(enemies.at(i));
    }
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
    rooms.at(currentRoomNumber)->removeItemsFromScene();
    this->currentRoomNumber = doorSelected->getRoomLink();
    rooms.at(currentRoomNumber)->addItemsToScene();

    QPoint newPos = rooms.at(currentRoomNumber)->getNewAvatarPosition(doorSelected->getPosition());
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
