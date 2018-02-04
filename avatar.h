#ifndef AVATAR_H
#define AVATAR_H

#include "mobileobject.h"
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QSet>

class Avatar: public QGraphicsPixmapItem{
public:
    Avatar();
    virtual void move();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void setCurrentPixmap(QPixmap pixmap);

private:
    QSet<int> keysPressed;
    int maxX;
    int maxY;
    int height;
    int width;
    int movementCounter;
    bool movingUp;
    bool movingDown;
    bool movingRight;
    bool movingLeft;
    QPixmap standing;
    QPixmap walkingOne;
    QPixmap walkingTwo;
    QPixmap currentPixmap;
};

#endif // AVATAR_H
