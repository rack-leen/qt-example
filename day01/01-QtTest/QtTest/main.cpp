#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //有且只有一个应用程序类
    QApplication a(argc, argv);

    //Widget继承于QWidget类,QWidget是一个窗口基类
    Widget w; //w就是一个窗口
    w.show();

    //让程序一直执行，等待用户操作
    //等待事件发生
    return a.exec();
}
