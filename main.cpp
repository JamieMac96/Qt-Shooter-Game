#include <QApplication>
#include <QGraphicsItem>
#include "avatar.h"
#include "stdio.h"
#include <QGraphicsScene>
#include <QGraphicsView>

/**/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    Avatar *avatar = new Avatar();
    avatar->setRect(0, 0, 100, 100);

    scene->addItem(avatar);

    avatar->setFlag(QGraphicsItem::ItemIsFocusable);
    avatar->setFocus();


    QGraphicsView *view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
