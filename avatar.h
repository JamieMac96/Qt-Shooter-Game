#ifndef AVATAR_H
#define AVATAR_H
// DIRECTIVES
#include "mobileitem.h"
#include "spritesheetdescriptor.h"
#include "spritemanager.h"
#include "collidableitem.h"
#include "healthbar.h"
#include <QKeyEvent>
#include <QPixmap>
#include <QSet>
#include <QPoint>

using namespace std;

class Avatar: public MobileItem, public CollidableItem{

public:
    // PROTOTYPES
    Avatar();
    ~Avatar();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool handleCollision();
    bool isDead() const;
    void refresh();
    HealthBar* getHealthBar();

private:
    QPoint getGunPosition() const;
    void updatePixmap();
    vector< SpriteSheetDescriptor > getSpriteSheetDescriptors();

    // POINTERS
    HealthBar* healthBar;
    SpriteManager* sManager;
    QImage spritesheet;
    vector< SpriteSheetDescriptor > spritesRequired;
};

#endif // AVATAR_H
