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
    void refresh();
    void generateBulletPlacement();

private:
    int maxX;
    int maxY;
    int height;
    int width;
};

#endif // AVATAR_H
