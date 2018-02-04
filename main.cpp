#include "zork.h"

/**/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Zork zork(&a);
    zork.run();
}
