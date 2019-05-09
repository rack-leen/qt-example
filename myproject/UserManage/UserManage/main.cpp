#include "content.h"
#include <QApplication>
#include <QTextCodec>
#include <QSplitter> //控制子窗口
#include <QListWidget> //窗口列表

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QFont font("",12)
    //a.setFont(font)

    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,0); //使得窗口水平
    splitterMain->setOpaqueResize(true);
    QListWidget *list = new QListWidget(splitterMain);//将子窗口组成窗口列表
    list->insertItem(0,QObject::tr("基本信息"));
    list->insertItem(1,QObject::tr("联系方式"));
    list->insertItem(2,QObject::tr("详细资料"));

    Content *content = new Content(splitterMain);

    QObject::connect(list , &QListWidget::currentRowChanged , content->stack , &QStackedWidget::setCurrentIndex);

    splitterMain->setWindowTitle("修改用户资料");
    splitterMain->setMaximumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->show();

    return a.exec();
}
