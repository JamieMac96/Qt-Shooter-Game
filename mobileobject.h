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
    int getCurrentDirection();
    void setMovementFlags(int direction);

protected:
    int maxX;
    int maxY;
    bool movingUp;
    bool movingDown;
    bool movingRight;
    bool movingLeft;
    bool shooting;
    int movementCounter;
    int spriteSpacingHorizontal;
    int spriteSpacingVertical;
    int spriteCounter;

    // For the mobile object's direction:
    // 0 --> Down Right
    // 1 --> Right
    // 2 --> Up Right
    // 3 --> Up
    // 4 --> Up Left
    // 5 --> Left
    // 6 --> Down Left
    // 7 --> Down
    int currentDirection;
    vector< vector<QPixmap> > spriteList;
};

#endif // MOVABLEOBJECT_H
