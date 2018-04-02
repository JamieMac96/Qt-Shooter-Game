#include "map.h"
#include "pair.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

Map::Map(Avatar* avatar){
    this->avatar = avatar;
}

Map::~Map(){
    // Delete the rooms from memory
    for(unsigned int i = 0; i < rooms.size(); i++){
        delete rooms.at(i);
    }
    rooms.clear();
}

Room* Map::getRoom(int index) const{
    return rooms.at(index);
}

void Map::setRooms(vector< Room* >& roomList){
    rooms = roomList;
}

void Map::setCurrentRoomNumber(int number){
    this->currentRoomNumber = number;
}

// REFERENCES
void Map::setEnemies(vector< vector< Enemy* > >& enemies)
{
    // if enmies.size() == rooms.size() then there
    // will be a list of enemies for each room
    int loopCondition = min(enemies.size(), rooms.size());

    for(int i = 0; i < loopCondition; i++){
        this->rooms.at(i)->setEnemies(enemies.at(i));
    }
}

// This function connects two rooms on the map by creating connecting
// doors in each of the rooms.
// The first two parameters pecify which rooms we wish to connect.
// The third parameter specifies which side of the FIRST room that the
// door will be on
// COERCION
void Map::connectRooms(QPixmap doorImage,
                       unsigned int firstRoomNumber,
                       unsigned int secondRoomNumber,
                       int position){
    string errorMessage = "Error! Invalid room number passed.";

    if(firstRoomNumber >= rooms.size()) throw invalid_argument(errorMessage);
    if(secondRoomNumber >= rooms.size()) throw invalid_argument(errorMessage);

    int secondPos = abs(position - 2);

    Pair< Room* > pRooms(rooms.at(firstRoomNumber),
                        rooms.at(secondRoomNumber));

    QPoint doorOnePosition = pRooms.getFirst()->getDoorPosition(position);
    QPoint doorTwoPosition = pRooms.getSecond()->getDoorPosition(secondPos);

    Door* doorOne = new Door(secondRoomNumber, doorImage, doorOnePosition);
    Door* doorTwo = new Door(firstRoomNumber, doorImage, doorTwoPosition);

    pRooms.getFirst()->addDoor(doorOne);
    pRooms.getSecond()->addDoor(doorTwo);
}


void Map::refresh(){
    Room* currentRoom = rooms.at(currentRoomNumber);
    vector< Door* > doors = currentRoom->getDoors();

    currentRoom->refresh();
    avatar->refresh();

    for(unsigned int i = 0; i < doors.size(); i++){
        Door *currentDoor = doors.at(i);
        if(currentDoor->handleCollision()){
            moveToRoom(currentDoor);
        }
    }
}

void Map::moveToRoom(Door* doorSelected){
    rooms.at(currentRoomNumber)->removeItemsFromScene();
    currentRoomNumber = doorSelected->getRoomLink();
    rooms.at(currentRoomNumber)->addItemsToScene();

    QPoint newPos = rooms.at(currentRoomNumber)->
                    getNewAvatarPosition(doorSelected->getPosition());

    avatar->setPos(newPos);
}

int Map::size() const{
    return rooms.size();
}

bool Map::isCleared() const{
    for(unsigned int i = 0; i < rooms.size(); i++){
        if(!rooms.at(i )->isCleared()){
            return false;
        }
    }

    return true;
}
