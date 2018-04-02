#ifndef ENEMY_H
#define ENEMY_H

#include "mobileitem.h"
#include "spritesheetdescriptor.h"
#include "spritemanager.h"
#include "collidableitem.h"

using namespace std;

class Enemy: public MobileItem{
public:
    Enemy();
    ~Enemy();
    int getCurrentDirection();
    bool isDead() const;
    void setDead();
    void refresh();
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
