#include "game.h"
#include "avatar.h"
#include "enemy.h"
#include "stdio.h"
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
    map         = new Map(maxX ,maxY, avatarPtr);
    currentRoom = 0;
}

void Game::run()
{
    // TODO: The avatar does not work if you click on the screen.
    // Likely due to a change in focus due to the click.
    // Needs to be fixed at some point

    scene->setSceneRect(0,0,maxX,maxY);
    scene->setBackgroundBrush(QBrush(QImage(":images/Game_Background.png")));

    map->addRooms(generateRooms());

    for(int i = 0; i < map->size(); i++){
        map->getRoom(i)->setEnemies(generateEnemies(5));
    }

    map->setCurrentRoomNumber(0);

    map->getRoom(currentRoom)->addItemsToScene();
    scene->addItem(avatarPtr);

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
    QPoint doorOnePosition(maxX / 2, 0);
    QPoint doorTwoPosition(maxX / 2, maxY - 150);

    Door *doorOne = new Door(1, scaledDoor, doorOnePosition);
    Door *doorTwo = new Door(0, scaledDoor, doorTwoPosition);

    vector< Room* > rooms;
    Room *roomOne = new Room(0, this->scene);
    Room *roomTwo = new Room(1, this->scene);
    roomOne->addDoor(doorOne);
    roomTwo->addDoor(doorTwo);

    rooms.push_back(roomOne);
    rooms.push_back(roomTwo);

    return rooms;
}

vector<Enemy *> Game::generateEnemies(int numEnemies){
    vector<Enemy *> enemies;

    // Create enemies
    for(int i = 0; i < numEnemies ; i++){
        Enemy *enemy = new Enemy();
        int x = rand() % maxX;
        int y = rand() % maxY;
        enemy->setPos(x, y);
        enemies.push_back(enemy);
    }

    return enemies;
}


