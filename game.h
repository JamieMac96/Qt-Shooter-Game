#include "avatar.h"
#include "map.h"
#include <vector>
#include <QApplication>
#include <QGraphicsScene>

#ifndef GAME_H
#define GAME_H


class Game
{

public:
    Game(QApplication *app);
    void run();

private:
    bool won();
    bool lost();
    vector< Enemy* > generateEnemies(int numEnemies);
    vector< Room* > generateRooms();

    QApplication *app;
    QGraphicsScene *scene;
    Map* map;
    Avatar *avatarPtr;
    int currentRoom;
    const int maxX = 1200;
    const int maxY = 700;
    const double frameRate = 30;
    const double frameTime = (1 / frameRate) * 1000;

};

#endif // GAME_H
