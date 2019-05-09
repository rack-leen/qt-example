#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this); //通过this指针指定父对象
    b1.setText("close");
    b1.move(200,200);

    b2 = new QPushButton(this); //为指针分配内存空间，通过this指针指向父对象
    b2->setText("abcz");
    b2->move(500,500);

    //信号与槽，作用于按钮
    connect(&b1 , &QPushButton::pressed , this , &MainWidget::close);
    /*
     * &b1 : 信号发生者
     * &QPushButton::pressd : 处理的信号，&发送者的类名::信号名字
     * &this : 信号接受者
     * &MainWidget::close : 槽函数名字，信号处理函数　&接收者的类名::槽函数名字
     */

    /* 自定义槽，普通函数的用法
     * QT5:任意的成员函数，普通全局函数，静态函数
     * 槽函数需要与信号一致（参数，返回值）
     * 由于信号都没有返回值，槽函数因此也没有返回值
     */

    connect(b2 , &QPushButton::released , this , &MainWidget::myslot);
    connect(b2,&QPushButton::released , &b1 , &QPushButton::hide);
    /* 信号可以理解为需要发送的信息
     * 槽函数可以看做是接收信息的手机
     */

    setWindowTitle("MainWindow");
    //this->setWindowTitle("MainWindow");//两者等价

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);


    //显示子窗口
    //w.show(); //这里的w是定义的子窗口
    connect(&b3 , &QPushButton::released , this , &MainWidget::changeWin);


    //处理子窗口信号
    //从子窗口发送自定义的信号到主窗口，通过主窗口的处理函数处理信号
    //用函数指针指向信号
    void (SubWidget::*funSignal)() = &SubWidget::mySignal ;
    connect(&w , funSignal , this , &MainWidget::dealSub);

    void (SubWidget::*testSignal)(int , QString) = &SubWidget::mySignal;
    connect(&w , testSignal , this , &MainWidget::dealSlot);

    //connect(&w , SIGNAL(mySignal()),this , slots::dealSlot());
    //lambda 表达式
    //C++11新增特性
    //QT配合信号使用非常方便
    QPushButton *b4 = new QPushButton(this) ;
    b4->setText("la bda表达式");
    b4->move(400,100);

    int a=100 , b=30 ;
    connect(b4 , &QPushButton::released ,
            //= : 把外部所有局部变量、类中所有成员以值传递方式
            //this : 类中所有成员以值传递方式
            //& : 把外部所有局部变量以值传递，引用符号
                [=](/*bool isCheck*/) mutable //mutable允许改变其中变量的值
                {
                        b4->setText("1231");
                        qDebug() << "asdgsdg" ;
                        qDebug() << a << b ;
                        a = 11 ; //受mutable控制
                        qDebug() << a ;
                       // qDebug() << isCheck ; //输出信号默认参数
                }
            );
    resize(500,500); //控制窗口大小
}

void MainWidget::dealSlot(int a , QString str)
{
    qDebug() << a << str.toUtf8().data() ;
}

void MainWidget::myslot()
{
    b2->setText("123");
}

void MainWidget::changeWin()
{
    //显示子窗口
    w.show();
    //隐藏主窗口
    this->hide();
}

void MainWidget::dealSub()
{
    //隐藏子窗口
    w.hide();
    //显示主窗口
    show();
}

MainWidget::~MainWidget()
{

}
