#include "clockdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClockDialog clock ;
    clock.show();

    return a.exec();
}
