#include "clockdialog.h"
#include <QTime>
#include <QTimer>
#include <QMouseEvent> //鼠标事件头文件

ClockDialog::ClockDialog(QWidget *parent)
                    :QLCDNumber (parent)
{
    //设置时钟颜色
    QPalette p = palette();
    p.setColor(QPalette::Window,Qt::blue); //设置窗体颜色为蓝色
    setPalette(p); //设置调色板颜色

    setWindowFlags(Qt::FramelessWindowHint); //设置一个没有面板边框和标题栏的窗口

    setWindowOpacity(0.5); //设置窗口透明度,不能用于x11

    QTimer *timer = new QTimer(this) ; //新建一个定时器对象
    connect(timer , &QTimer::timeout , this , &ClockDialog::showTime);
    timer->start(1000); //以1000毫秒为周期启动定时器
    showTime(); //显示当前时间
    resize(150,60); //窗口尺寸
    showColon = true ;


}

void ClockDialog::showTime()
{
    QTime time = QTime::currentTime(); //导入当前时间
    QString text = time.toString("hh:mm"); //将导入的时间转为字符串

    if(showColon) //如果为真
    {
        text[2] = ':';
        showColon = false ; //此时标志转为false
    }
    else
    {
        text[2] = ' ';
        showColon = true ;
    }

    display(text);
}

void ClockDialog::MousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) // 如果点鼠标左键
    {
        dragPosition = event->globalPos()-frameGeometry().topLeft(); //鼠标点全局位置-窗体左顶部位置=偏移值
        event->accept();
    }
    else if(event->button() == Qt::RightButton) //如果点鼠标右键
    {
        close(); //直接关闭
    }
}

void ClockDialog::MouseMoveEvent(QMouseEvent *event)
{
    if(event->button() && Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition); //鼠标点全局位置-偏移值
        event->accept() ;
    }
}

