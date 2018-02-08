#ifndef AVATAR_H
#define AVATAR_H

#include "mobileobject.h"
#include "animatedobject.h"
#include <QKeyEvent>
#include <QPixmap>
#include <QSet>

class Avatar: public MobileObject{
public:
    Avatar();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);


private:
    int maxX;
    int maxY;
    int height;
    int width;
    int movementCounter;
};

#endif // AVATAR_H
