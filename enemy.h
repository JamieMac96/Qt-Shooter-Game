#ifndef ENEMY_H
#define ENEMY_H

#include "mobileobject.h"
#include "spritesheetdescriptor.h"
#include "spritemanager.h"

using namespace std;

class Enemy: public MobileObject
{

public:
    Enemy();
    int getCurrentDirection();
    void refresh();
    bool isDead() const;
    void setDead();
    vector <SpriteSheetDescriptor> getSpriteSheetDescriptors();

private:
    void updateDirectionFlags();
    void updatePixmap();

    int height;
    int width;
    bool dead;
    QImage spritesheet;
    vector< SpriteSheetDescriptor > spritesRequired;
    SpriteManager *sManager;

};

#endif // ENEMY_H
