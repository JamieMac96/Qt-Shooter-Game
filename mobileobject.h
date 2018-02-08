#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "animatedobject.h"
#include <QPixmap>

using namespace std;

class MobileObject: public AnimatedObject
{
public:
    MobileObject(int maxX, int maxY);
    virtual void move();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void updatePixmap();
    void initializeSpriteVectors();

protected:
    int maxX;
    int maxY;
    bool movingUp;
    bool movingDown;
    bool movingRight;
    bool movingLeft;
    int movementCounter;
    int spriteSpacingHorizontal;
    int spriteSpacingVertical;
    int spriteCounter;
    int currentDirection;

    vector< vector<QPixmap> > spriteList;
};

#endif // MOVABLEOBJECT_H
