#include "animatedobject.h"
#include <string>


AnimatedObject::AnimatedObject(string filename, int width, int height)
{
    this->filename = filename;
    this->width = width;
    this->height = height;

    spritesheet = new QImage(":images/cowboy.png");
}
