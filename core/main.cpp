#include "qtticker.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtTicker w;
    w.show();
    return a.exec();
}
