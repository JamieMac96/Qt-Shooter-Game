#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsTextItem>

class HealthBar: public QGraphicsTextItem{
public:
    HealthBar(int initialValue);
    int getHealth() const;
    // OPERATOR OVERLOADING
    void operator++(int);
    void operator--(int);
private:
    int health;
};

#endif // HEALTHBAR_H
