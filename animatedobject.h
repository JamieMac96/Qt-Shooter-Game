#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include <QGraphicsPixmapItem>
#include <QImage>
#include <string>

using namespace std;

class AnimatedObject: public QGraphicsPixmapItem
{
public:
    AnimatedObject(string filename, int width, int height);
protected:
    string filename;
    int width;
    int height;
    QImage *spritesheet;
};

#endif // ANIMATEDOBJECT_H
