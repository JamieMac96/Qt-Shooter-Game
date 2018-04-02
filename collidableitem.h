#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H

// ABSTRACT CLASS
class CollidableItem{

public:
    CollidableItem();
    // PURE VIRTUAL FUNCTION
    virtual bool handleCollision() = 0;
};

#endif // COLLIDABLEOBJECT_H
