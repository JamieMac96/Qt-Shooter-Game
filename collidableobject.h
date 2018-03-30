#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H


class CollidableObject
{

public:
    CollidableObject();
    virtual bool handleCollision() = 0;
};

#endif // COLLIDABLEOBJECT_H
