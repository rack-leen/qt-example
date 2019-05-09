#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "subwidget.h"
#include <QWidget>
#include <QPushButton>

class MainWidget : public QWidget
{
    Q_OBJECT

public :
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void myslot(); //自定义槽函数
    void changeWin(); //显示窗口
    void dealSub(); //处理子窗口信号
    void dealSlot(int , QString);

private:
    QPushButton b1 ;
    QPushButton *b2 ;
    QPushButton b3 ;
    SubWidget w ; //定义子窗口
};

#endif // MAINWIDGET_H
