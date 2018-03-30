#include "game.h"
#include "avatar.h"
#include "enemy.h"
#include "stdio.h"
#include "healthbar.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTime>

Game::Game(QApplication *app)
{
    this->app   = app;
    scene       = new QGraphicsScene();
    avatarPtr   = new Avatar();
    map         = new Map(avatarPtr);
    currentRoom = 0;
}

void Game::run()
{
    // TODO: The avatar does not work if you click on the screen.
    // Likely due to a change in focus due to the click.
    // Needs to be fixed at some point

    scene->setSceneRect(0,0,maxX,maxY);
    scene->setBackgroundBrush(QBrush(QImage(":images/Game_Background.png")));

    map->setRooms(generateRooms());
    map->setEnemies(generateEnemies(5));

    map->setCurrentRoomNumber(0);

    map->getRoom(currentRoom)->addItemsToScene();
    scene->addItem(avatarPtr);

    scene->addItem(avatarPtr->getHealthBar());

    QGraphicsView *view = new QGraphicsView(scene);
    view->show();

    QTime last_update = QTime::currentTime();

    while(!(this->won() || this->lost())){
        app->processEvents();
        QTime currentTime = QTime::currentTime();
        int timeSinceLastUpdate = last_update.msecsTo(currentTime);

        if(timeSinceLastUpdate > frameTime){
            avatarPtr->refresh();
            map->refresh();
            timeSinceLastUpdate-=frameTime;
            last_update = QTime::currentTime();

        }
    }

    this->app->exit();
}

bool Game::won()
{
    for(unsigned int i = 0; i < map->size(); i++){
        if(!map->getRoom(i)->isCleared()){
            return false;
        }
    }

    return true;
}

bool Game::lost()
{
    if(avatarPtr->isDead()) return true;
}

vector<Room *> Game::generateRooms()
{
    QImage doorImage;

    doorImage.load(":images/door.png");
    QPixmap doorPixmap = QPixmap::fromImage(doorImage.copy(0, 0, 30, 50));
    QPixmap scaledDoor = doorPixmap.scaled(QSize(90, 150));

    vector< Room* > rooms;

    for(int i = 0; i < 5; i++){
        Room *newRoom = new Room(i, this->scene, maxX, maxY);
        rooms.push_back(newRoom);
    }

    Door *doorOne = new Door(1, scaledDoor, rooms.at(0)->getLeftDoorPosition());
    Door *doorTwo = new Door(0, scaledDoor, rooms.at(1)->getRightDoorPosition());
    Door *doorThree = new Door(2, scaledDoor, rooms.at(1)->getBottomDoorPosition());
    Door *doorFour = new Door(1, scaledDoor, rooms.at(2)->getTopDoorPosition());
    Door *doorFive = new Door(3, scaledDoor, rooms.at(2)->getLeftDoorPosition());
    Door *doorSix = new Door(4, scaledDoor, rooms.at(2)->getBottomDoorPosition());
    Door *doorSeven = new Door(2, scaledDoor, rooms.at(3)->getRightDoorPosition());
    Door *doorEight = new Door(2, scaledDoor, rooms.at(4)->getTopDoorPosition());

    rooms.at(0)->addDoor(doorOne);
    rooms.at(1)->addDoor(doorTwo);
    rooms.at(1)->addDoor(doorThree);
    rooms.at(2)->addDoor(doorFour);
    rooms.at(2)->addDoor(doorFive);
    rooms.at(2)->addDoor(doorSix);
    rooms.at(3)->addDoor(doorSeven);
    rooms.at(4)->addDoor(doorEight);

    return rooms;
}

vector< vector<Enemy *> > Game::generateEnemies(int numEnemies){
    vector< vector<Enemy *> > enemies;

    // Create enemies
    for(int i = 0; i < map->size(); i++){
        vector< Enemy* > subenemies;
        for(int j = 0; j < numEnemies ; j++){
            Enemy *enemy = new Enemy();
            int x = rand() % maxX;
            int y = rand() % maxY;
            enemy->setPos(x, y);
            subenemies.push_back(enemy);
        }
        enemies.push_back(subenemies);
        subenemies.clear();
    }

    return enemies;
}


