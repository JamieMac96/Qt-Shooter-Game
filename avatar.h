#ifndef AVATAR_H
#define AVATAR_H

#include <QGraphicsRectItem>

class Avatar: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // AVATAR_H
