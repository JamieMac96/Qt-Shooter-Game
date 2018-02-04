#ifndef GAME_H
#define GAME_H

#include <QApplication>

class Zork
{
public:
    Zork(QApplication *app);
    void run();

private:
    QApplication *app;
};

#endif // GAME_H
