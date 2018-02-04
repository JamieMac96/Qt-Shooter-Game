#include "zork.h"
#include "avatar.h"
#include "stdio.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTime>

Zork::Zork(QApplication *app)
{
    this->app = app;
}

void Zork::run()
{
    //TODO: The avatar does not work if you click on the screen.
    // Likely due to a change in focus due to the click.
    // Needs to be fixed at some point

    const double FRAME_RATE = 25;
    const double FRAME_TIME = (1 / FRAME_RATE) * 1000;

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,960,540);
    scene->setBackgroundBrush(QBrush(QImage(":images/Game_Background.png")));

    Avatar *avatar = new Avatar();

    scene->addItem(avatar);

    QGraphicsView *view = new QGraphicsView(scene);
    view->show();

    QTime last_update = QTime::currentTime();

    while(1){
        this->app->processEvents();

        QTime currentTime = QTime::currentTime();

        int timeSinceLastUpdate = last_update.msecsTo(currentTime);

        if(timeSinceLastUpdate > FRAME_TIME){

            avatar->move();

            timeSinceLastUpdate-=FRAME_TIME;

            last_update = QTime::currentTime();

        }
    }

    this->app->exec();
}
