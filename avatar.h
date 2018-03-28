#ifndef AVATAR_H
#define AVATAR_H

#include "mobileobject.h"
#include "spritesheetdescriptor.h"
#include "spritemanager.h"
#include <QKeyEvent>
#include <QPixmap>
#include <QSet>
#include <QPoint>

using namespace std;

class Avatar: public MobileObject{

public:
    Avatar();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void refresh();
    bool isDead();

private:
    void updatePixmap();
    QPoint getGunPosition();
    vector< SpriteSheetDescriptor > getSpriteSheetDescriptors();

    int height;
    int width;
    bool dead;
    QImage spritesheet;
    vector< SpriteSheetDescriptor > spritesRequired;
    SpriteManager *sManager;

};

#endif // AVATAR_H
