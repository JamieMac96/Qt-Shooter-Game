#include "game.h"
#include "avatar.h"
#include "enemy.h"
#include "stdio.h"
#include "healthbar.h"
#include "gameconstants.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTime>
#include <iostream>
#include <unistd.h>

using namespace std;

Game::Game(QApplication *app){
    this->app         = app;
    this->scenePtr    = new QGraphicsScene();
    this->avatarPtr   = new Avatar();
    this->mapPtr      = new Map(avatarPtr);
    this->currentRoom = 0;
}

void Game::run(){
    const double frameTime = (1 / frameRate) * 1000;

    generateMap();

    scenePtr->setSceneRect(0, 0, maximumX, maximumY);
    scenePtr->setBackgroundBrush(QBrush(QImage(":images/Game_Background.png")));
    scenePtr->addItem(avatarPtr);
    scenePtr->addItem(avatarPtr->getHealthBar());


    QGraphicsView *view = new QGraphicsView(scenePtr);
    view->show();

    QTime last_update = QTime::currentTime();

    while(!(isOver())){
        app->processEvents();
        QTime currentTime = QTime::currentTime();
        int timeSinceLastUpdate = last_update.msecsTo(currentTime);

        if(timeSinceLastUpdate > frameTime){
            avatarPtr->refresh();
            mapPtr->refresh();
            timeSinceLastUpdate-=frameTime;
            last_update = QTime::currentTime();

        }
    }

    sleep(1);

    // MEMOMRY MANAGEMENT
    mapPtr->~Map();
    delete scenePtr;
    delete view;

    this->app->exit();
}

bool Game::won() const{
    for(int i = 0; i < mapPtr->size(); i++){
        if(!mapPtr->getRoom(i)->isCleared()){
            return false;
        }
    }

    return true;
}

bool Game::lost() const{
    return avatarPtr->isDead();
}

bool Game::isOver() const{
    return won() || lost();
}

void Game::generateMap(){
    QImage doorImage;
    doorImage.load(":images/door.png");
    QPixmap doorPixmap = QPixmap::fromImage(doorImage.copy(0, 0, 30, 50));
    QPixmap scaledDoor = doorPixmap.scaled(QSize(90, 150));

    vector< Room* > rooms;

    for(unsigned int i = 0; i < 5; i++){
        Room *newRoom = new Room(i, this->scenePtr, maximumX, maximumY);
        rooms.push_back(newRoom);
    }

    mapPtr->setRooms(rooms);

    mapPtr->connectRooms(scaledDoor, 0, 1, 3);
    mapPtr->connectRooms(scaledDoor, 1, 2, 2);
    mapPtr->connectRooms(scaledDoor, 2, 3, 3);
    mapPtr->connectRooms(scaledDoor, 2, 4, 2);

    vector< vector< Enemy* > > enemies = generateEnemies(5);

    mapPtr->setEnemies(enemies);
    mapPtr->setCurrentRoomNumber(0);
    mapPtr->getRoom(currentRoom)->addItemsToScene();
}

vector< vector<Enemy *> > Game::generateEnemies(int numEnemies){
    vector< vector<Enemy *> > enemies;

    // Create enemies
    for(int i = 0; i < mapPtr->size(); i++){
        vector< Enemy* > subenemies;
        for(int j = 0; j < numEnemies ; j++){
            Enemy *enemy = new Enemy();
            int x = rand() % maximumX;
            int y = rand() % maximumY;
            enemy->setPos(x, y);
            subenemies.push_back(enemy);
        }
        enemies.push_back(subenemies);
        subenemies.clear();
    }

    return enemies;
}
