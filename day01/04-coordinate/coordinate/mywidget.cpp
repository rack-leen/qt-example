#include "mywidget.h"
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    move(0,100);
    resize(500,300);
    QPushButton *b1 = new QPushButton(this);
    b1->move(0,0);
    b1->setText("bush");
    b1->resize(300,100);

    QPushButton *b2 = new QPushButton(b1);
    b2->move(0,0);
    b2->setText("mylove");
    b2->resize(100,50);
}

MyWidget::~MyWidget()
{

}
