#include "door.h"
#include "avatar.h"
#include <typeinfo>

Door::Door(int roomLink, QPixmap pixmap, QPoint position){
    this->setPixmap(pixmap);
    this->setPos(position);
    this->position = position;
    this->roomLink = roomLink;

}

int Door::getRoomLink() const{
    return roomLink;
}

QPoint Door::getPosition() const{
    return position;
}

bool Door::collisionOccured(){
    QList< QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*colliding_items[i]) == typeid(Avatar)){
            return true;
        }
    }
}
