#include <QApplication>
#include <QtWidgets> //窗口基类
#include <QPushButton> //按钮类

int main(int argc , char **argv)
{
    QApplication app(argc,argv) ;
    QWidget w ;
    w.setWindowTitle("学生信息管理系统");//设置窗口标题

    //将按钮放入窗口之中有两种方法
    //1.设置父对象
    //2.通过构造函数传参

    //1.设置父对象
    //设置按钮
    QPushButton b ;
    b.setText("this is a test");
    //为按钮设置父对象，使得按钮放置在父对象窗口之中
    b.setParent(&w);
    //移动按钮位置
    b.move(100,100);

    QPushButton b1(&w); //通过构造函数传参
    b1.setText("app");
    b1.move(800,400);

    w.show() ;

    app.exec();
    return 0 ;
}

