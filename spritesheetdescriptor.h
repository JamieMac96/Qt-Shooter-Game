#ifndef SPRITESHEETROWDESCRIPTOR_H
#define SPRITESHEETROWDESCRIPTOR_H

#include <QPoint>


/*
 * This class is used in order to describe a row of a
 * spritesheet that will be used in the program.
 *
 * Due to the unpredictable nature of spritesheet layouts
 * it is hard to read the sprite data required without writing
 * a seperate funtion for each time we read a different spritesheet.
 *
 * For example if we want to read 5 sprites from the middle of the
 * spritesheet we can specify that using this class. Then the
 * spritesheetmanager will process this information and read in the
 * currect information.
 */
class SpriteSheetDescriptor{

public:
    //Constructors
    SpriteSheetDescriptor();
    SpriteSheetDescriptor(QPoint point, int width, int height, int numEls);

    //Setters
    void setStartPoint(QPoint point);
    void setStartPoint(int x, int y);
    void setSpriteWidth(int width);
    void setSpriteHeight(int height);
    void setNumSprites(int numEls);

    //Getters
    QPoint getStartPoint() const;
    int getSpriteWidth() const;
    int getSpriteHeight() const;
    int getNumSprites() const;

private:
    QPoint startPoint;
    int spriteWidth;
    int spriteHeight;
    int numSprites;

};
#endif // SPRITESHEETROWDESCRIPTOR_H
