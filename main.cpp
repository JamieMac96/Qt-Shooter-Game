#include "game.h"

/**/

int main(int argc, char *argv[])
{
    QApplication *a = new QApplication(argc, argv);

    Game zork(a);
    zork.run();
}
