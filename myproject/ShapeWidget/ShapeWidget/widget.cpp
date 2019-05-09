#include "widget.h"
#include <QPixmap>
#include <QPainter>
#include <QBitmap>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pix ;
    pix.load("1.jpg",0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));
}


void Widget::MousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    else if(event->button() == Qt::RightButton)
    {
        close();
    }
}

void Widget::MouseMoveEvent(QMouseEvent *event)
{
    if(event->button() && Qt::LeftButton)
    {
       move(event->globalPos()-dragPosition);
       event->accept();
    }
}

void Widget::PaintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap("1.jpg"));
    event->accept();
}

Widget::~Widget()
{

}
