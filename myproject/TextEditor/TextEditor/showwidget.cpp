#include "showwidget.h"

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{
    imageLabel = new QLabel ;
    imageLabel->setScaledContents(true);

    mainText = new QTextEdit ; //创建文件编辑区


    QHBoxLayout *mainLayout = new QHBoxLayout(this) ;
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(mainText); //将文本编辑区加入水平布局


}
