#include "room.h"

Room::Room(int id, QGraphicsScene *scene){
    this->id = id;
    this->scene = scene;
}

Room::~Room(){

}

vector<Door *> Room::getDoors(){
    return doors;
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
