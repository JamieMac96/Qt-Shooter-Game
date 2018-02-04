#include "avatar.h"
#include "stdio.h"
#include <iostream>
#include <QDebug>
#include <QPixmap>
#include <QKeyEvent>

using namespace std;

Avatar::Avatar(){
    //TODO: Refactor into logical inheritance hierarchy
    this->height = 80;
    this->width = 40;
    this->maxX = 940;
    this->maxY = 500;
    this->movingUp = false;
    this->movingDown = false;
    this->movingRight = false;
    this->movingLeft = false;
    this->movementCounter = 0;


    QImage *spritesheet = new QImage(":/images/avatar.png");
    cout << "reached constructor" << endl;
    QImage enlarged = spritesheet->scaled(460, 460, Qt::KeepAspectRatio);
    this->standing = QPixmap::fromImage(enlarged.copy(0, 0, width, height));
    this->walkingOne = QPixmap::fromImage(enlarged.copy(width, 0, width, height));
    this->walkingTwo = QPixmap::fromImage(enlarged.copy((width * 2),0, width, height));
    this->currentPixmap = standing;
    this->setPixmap(currentPixmap);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    cout << "reached constructor end" << endl;
}

void Avatar::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        this->movingUp = true;
    }
    if(event->key() == Qt::Key_Down){
        this->movingDown = true;
    }
    if(event->key() == Qt::Key_Right){
        this->movingRight = true;
    }
    if(event->key() == Qt::Key_Left){
        this->movingLeft = true;
    }
}

void Avatar::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        this->movingUp = false;
    }
    if(event->key() == Qt::Key_Down){
        this->movingDown = false;
    }
    if(event->key() == Qt::Key_Right){
        this->movingRight = false;
    }
    if(event->key() == Qt::Key_Left){
        this->movingLeft = false;
    }
}

void Avatar::move(){
    movementCounter++;

    if(movingUp){
        this->moveUp();
    }
    if(movingDown){
        this->moveDown();
    }
    if(movingRight){
        this->moveRight();
    }
    if(movingLeft){
        this->moveLeft();
    }
    if(movingUp || movingDown || movingRight || movingLeft){
        if(currentPixmap.toImage() == standing.toImage()){
            this->setCurrentPixmap(walkingOne);
        }
        else if(movementCounter % 5 == 0){
            if(currentPixmap.toImage() == walkingTwo.toImage()){
                this->setCurrentPixmap(walkingOne);
            }
            else{
                this->setCurrentPixmap(walkingTwo);
            }
        }
    }
    else{
        this->setCurrentPixmap(standing);
    }
}

void Avatar::moveUp(){
    int nextY = ((((this->y() - 10)) < 0) ? 0 : (this->y() - 10));
    this->setPos(this->x(), nextY);
}

void Avatar::moveDown(){
    int nextY = ((this->y() + 10 + height/2) > this->maxY) ? this->y(): this->y() + 10;
    this->setPos(this->x(), nextY);

}

void Avatar::moveRight(){
    int nextX = ((((this->x() + 10 + width/2)) > this->maxX) ? this->x() : (this->x() + 10));
    this->setPos(nextX, this->y());
}

void Avatar::moveLeft(){
    int nextX = ((((this->x() - 10)) < 0) ? 0 : (this->x() - 10));
    this->setPos(nextX, this->y());
}

void Avatar::setCurrentPixmap(QPixmap pixmap){
    this->currentPixmap = pixmap;
    this->setPixmap(currentPixmap);
}
