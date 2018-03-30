#ifndef AVATAR_H
#define AVATAR_H

#include "mobileobject.h"
#include "spritesheetdescriptor.h"
#include "spritemanager.h"
#include "bullet.h"
#include "collidableobject.h"
#include "healthbar.h"
#include <QKeyEvent>
#include <QPixmap>
#include <QSet>
#include <QPoint>

using namespace std;

class Avatar: public MobileObject, public CollidableObject{

public:
    Avatar();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void refresh();
    bool handleCollision();
    bool isDead();
    HealthBar* getHealthBar();

private:
    void updatePixmap();
    QPoint getGunPosition();
    vector< SpriteSheetDescriptor > getSpriteSheetDescriptors();

    int height;
    int width;
    HealthBar* healthBar;
    QImage spritesheet;
    SpriteManager *sManager;
    vector< SpriteSheetDescriptor > spritesRequired;
    vector< Bullet > activeBullets;

};

#endif // AVATAR_H
