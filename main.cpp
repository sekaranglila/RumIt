#include "rumit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RumIt w;
    w.show();

    return a.exec();
}
