#ifndef DRAWER_H
#define DRAWER_H

#include <QWidget>
#include <QToolBox>
#include <QToolButton>


class Drawer : public QToolBox
{
public:
    Drawer(QWidget *parent = 0 , Qt::WindowFlags f=0);

private:
    //第一个工具盒
    QToolButton *toolButton1_1 ;
    QToolButton *toolButton1_2 ;
    QToolButton *toolButton1_3 ;
    QToolButton *toolButton1_4 ;
    QToolButton *toolButton1_5 ;

    //第二个工具盒
    QToolButton *toolButton2_1 ;
    QToolButton *toolButton2_2 ;

    //第三个工具盒
    QToolButton *toolButton3_1 ;
    QToolButton *toolButton3_2 ;

};

#endif // DRAWER_H
