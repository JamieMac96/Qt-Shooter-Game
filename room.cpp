#include "room.h"

Room::Room(int id, QGraphicsScene *scene, int maxX, int maxY){
    this->id = id;
    this->scene = scene;
    this->maxX = maxX;
    this->maxY = maxY;
}

Room::~Room(){

}

vector<Door *> Room::getDoors(){
    return doors;
}

QPoint Room::getRightDoorPosition(){
    return QPoint(maxX - 90, maxY / 2);
}

QPoint Room::getLeftDoorPosition(){
    return QPoint(0 , maxY / 2);
}

QPoint Room::getTopDoorPosition(){
    return QPoint(maxX / 2 , 0);
}

QPoint Room::getBottomDoorPosition(){
    return QPoint(maxX / 2 , maxY - 150);
}

void Room::addItemsToScene(){
    for(int i = 0; i < doors.size(); i++){
        scene->addItem(doors.at(i));
    }

    for(int i = 0; i < enemies.size(); i++){
        scene->addItem(enemies.at(i));
    }
}

void Room::removeItemsFromScene(){
    for(int i = 0; i < enemies.size(); i++){
        scene->removeItem(enemies.at(i));
    }

    for(int i = 0; i < doors.size(); i++){
        scene->removeItem(doors.at(i));
    }
}

void Room::setEnemies(vector<Enemy *> enemies){
    this->enemies = enemies;

    for(int i = 0; i < enemies.size(); i++){
        scene->addItem(enemies.at(i));
    }
}

void Room::refresh(){
    for(int i = 0; i < enemies.size(); i++){
        if(!enemies.at(i)->isDead()){
            enemies.at(i)->refresh();
        }
        else{
            delete enemies.at(i);
            enemies.erase(enemies.begin() + i);
        }
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
QPoint Room::getNewAvatarPosition(QPoint oldPosition){
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
