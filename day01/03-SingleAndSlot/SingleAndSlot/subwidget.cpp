#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("SubWindow");
    b.setParent(this);
    b.setText("welcome to you !");

    //子窗口中点击按钮信号，从而发送槽函数信息
    connect(&b , &QPushButton::clicked , this , &SubWidget::sendSlot);
    resize(400,300);
}

void SubWidget::sendSlot()
{
    //使用定义的信号
    emit mySignal();
    emit mySignal(250,"我是子窗口");
}
