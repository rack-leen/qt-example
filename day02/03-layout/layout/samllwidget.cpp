#include "samllwidget.h"
#include <QSpinBox> //旋转滚条
#include <QSlider> //水平滑条
#include <QHBoxLayout> //水平布局

SamllWidget::SamllWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *spin = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal,this); //设置滑条为水平

    //把空间添加到布局中
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(spin); //将spin部件增加到布局中
    hLayout->addWidget(slider);

    //setLayout(hLayout); //也可以用其设置布局，不需要指定父对象

    //用滑条控制滚条
    //这里需要强制转换是因为这个函数有整数和字符串两个重载函数，这里只需要整数型，所以需要强制转换
    connect(spin , static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged) ,slider , &QSlider::setValue);

    //用滚条反过来控制滑条
    connect(slider , &QSlider::valueChanged , spin , &QSpinBox::setValue);


}
