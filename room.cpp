#include "room.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

Room::Room(int id, QGraphicsScene *scene, int maxX, int maxY){
    this->id = id;
    this->scene = scene;
    this->maxX = maxX;
    this->maxY = maxY;
}

Room::~Room(){
    // Delete enemies
    for(unsigned int i = 0; i < enemies.size(); i++){
        delete enemies.at(i);
    }
    enemies.clear();

    //Delete doors
    for(unsigned int i = 0; i < doors.size(); i++){
        delete doors.at(i);
    }
    doors.clear();
}

vector<Door *> Room::getDoors() const{
    return doors;
}

QPoint Room::getRightDoorPosition() const{
    return QPoint(maxX - 90, maxY / 2 - 75);
}

QPoint Room::getLeftDoorPosition() const{
    return QPoint(0 , maxY / 2 - 75);
}

QPoint Room::getTopDoorPosition() const{
    return QPoint(maxX / 2 , 0);
}

QPoint Room::getBottomDoorPosition() const{
    return QPoint(maxX / 2 , maxY - 150);
}

// Provide and integer to specify which door postion we wish to retrieve
// 0 = TOP
// 1 = RIGHT
// 2 = BOTTOM
// 3 = LEFT
QPoint Room::getDoorPosition(int position) const{
    string errorMessage = "Error! Postion argument must be between 0 and 3.";
    if(position > 3 || position < 0){
        throw std::invalid_argument(errorMessage);
    }

    QPoint doorPosition;

    switch(position){
    case 0:
        doorPosition = getTopDoorPosition();
        break;
    case 1:
        doorPosition = getRightDoorPosition();
        break;
    case 2:
        doorPosition = getBottomDoorPosition();
        break;
    case 3:
        doorPosition = getLeftDoorPosition();
        break;
    }

    return doorPosition;
}

void Room::addItemsToScene(){
    for(unsigned int i = 0; i < doors.size(); i++){
        scene->addItem(doors.at(i));
    }

    for(unsigned int i = 0; i < enemies.size(); i++){
        scene->addItem(enemies.at(i));
    }
}

void Room::removeItemsFromScene(){
    for(unsigned int i = 0; i < enemies.size(); i++){
        scene->removeItem(enemies.at(i));
    }

    for(unsigned int i = 0; i < doors.size(); i++){
        scene->removeItem(doors.at(i));
    }
}

void Room::refresh(){
    for(unsigned int i = 0; i < enemies.size(); i++){
        if(!enemies.at(i)->isDead()){
            enemies.at(i)->refresh();
        }
        else{
            delete enemies.at(i);
            enemies.erase(enemies.begin() + i);
        }
    }
}

void Room::setEnemies(vector< Enemy* >& enemies){
    this->enemies = enemies;

    for(unsigned int i = 0; i < enemies.size(); i++){
        scene->addItem(enemies.at(i));
    }
}
void Room::addDoor(Door* door){
    doors.push_back(door);
}

bool Room::isCleared(){
    return enemies.empty();
}

// Based on the point at which the avatar left the old
// room we calculate the point they will enter the new room.
QPoint Room::getNewAvatarPosition(QPoint oldPosition) const{
    QPoint newPosition;

    int oldX = oldPosition.x();
    int oldY = oldPosition.y();
    int newX = 0;
    int newY = 0;

    if(oldX == 0){
        newX = maxX - 165;
    }
    else if(oldX == maxX - 90){
        newX = 40;
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

vector<Enemy *> Room::getEnemies() const{
    return enemies;
}
