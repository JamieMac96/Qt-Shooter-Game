#include "avatar.h"
#include "map.h"
#include <vector>
#include <QApplication>
#include <QGraphicsScene>

#ifndef GAME_H
#define GAME_H

class Game{

public:
    Game(QApplication *app);
    void run();

private:
    bool won() const;
    bool lost() const;
    bool isOver() const;
    vector< vector< Enemy* > > generateEnemies(int numEnemies);
    void generateMap();

    QApplication *app;
    QGraphicsScene *scenePtr;
    Map* mapPtr;
    Avatar *avatarPtr;
    int currentRoom;
};

#endif // GAME_H
