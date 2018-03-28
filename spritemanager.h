#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "spritesheetdescriptor.h"
#include <QPixmap>

using namespace std;

/*
 * This class is used to read, store and access sprites
 * that are used in the game.
 *
 * It is assumed that the sprites using this class are
 * sprites that can move in different directions.
 * As such we store them in a
 * vector of vectors. Essentially there are are number
 * of pixmaps for each individual direction and a
 * number of these directions.
 *
 * For example spriteList.at(0) may return the vector
 * of sprites that are used to animate movement to the right.
 */

class SpriteManager
{

public:
    SpriteManager(QImage spritesheet);
    void initializeSpriteList(vector< SpriteSheetDescriptor > descriptors);
    QPixmap getSprite(int direction, int animation);

private:
    vector< QPixmap > getSpriteSublist(int direction);

    QImage spritesheet;
    vector< vector< QPixmap > > spriteList;

};

#endif // SPRITEMANAGER_H
