#include "healthbar.h"
#include <QFont>
#include <iostream>

HealthBar::HealthBar(int initialValue): QGraphicsTextItem(){
    this->health = initialValue;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

int HealthBar::getHealth(){
    return health;
}

void HealthBar::operator++(int){
    health++;
    setPlainText(QString("Health: ") + QString::number(health));
}

void HealthBar::operator--(int){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}
