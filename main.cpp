#include "zork.h"

/**/

int main(int argc, char *argv[])
{
    QApplication *a = new QApplication(argc, argv);

    Zork zork(a);
    zork.run();
}
