#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>

using namespace std;

class MobileObject: public QGraphicsPixmapItem
{

public:
    MobileObject(int maxX, int maxY, int height, int width);
    virtual void move();
    virtual int getCurrentDirection();
    void setMovementFlags(int direction);
    void setSpeed(int speed);

private:
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    int speed;

protected:
    QImage *spritesheet;
    int maxX;
    int maxY;
    int height;
    int width;
    bool movingUp;
    bool movingDown;
    bool movingRight;
    bool movingLeft;
    bool shooting;
    int movementCounter;
    int spriteCounter;
    int currentDirection;

};

#endif // MOVABLEOBJECT_H
