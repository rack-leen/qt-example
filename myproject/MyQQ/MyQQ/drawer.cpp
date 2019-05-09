#include "drawer.h"
#include <QGroupBox>
#include <QVBoxLayout>

Drawer::Drawer(QWidget *parent , Qt::WindowFlags f)
            :QToolBox (parent,f)
{
    setWindowTitle(tr("My QQ"));

    //第一个工具盒中的按钮
    toolButton1_1 = new  QToolButton ;
    toolButton1_1->setText(tr("rack"));
    toolButton1_1->setIcon(QPixmap(""));
    toolButton1_1->setIconSize(QPixmap("").size());
    toolButton1_1->setAutoRaise(true);
    toolButton1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    toolButton1_2 = new  QToolButton ;
    toolButton1_2->setText(tr("leen"));
    toolButton1_2->setIcon(QPixmap(""));
    toolButton1_2->setIconSize(QPixmap("").size());
    toolButton1_2->setAutoRaise(true);
    toolButton1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    toolButton1_3 = new  QToolButton ;
    toolButton1_3->setText(tr("ra"));
    toolButton1_3->setIcon(QPixmap(""));
    toolButton1_3->setIconSize(QPixmap("").size());
    toolButton1_3->setAutoRaise(true);
    toolButton1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    toolButton1_4 = new  QToolButton ;
    toolButton1_4->setText(tr("ck"));
    toolButton1_4->setIcon(QPixmap(""));
    toolButton1_4->setIconSize(QPixmap("").size());
    toolButton1_4->setAutoRaise(true);
    toolButton1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    toolButton1_5 = new  QToolButton ;
    toolButton1_5->setText(tr("ack"));
    toolButton1_5->setIcon(QPixmap(""));
    toolButton1_5->setIconSize(QPixmap("").size());
    toolButton1_5->setAutoRaise(true);
    toolButton1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    QGroupBox *groupBox1 = new QGroupBox ;
    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1); //将groupBox1加入垂直布局
    layout1->setMargin(10); //各窗体之间显示的间距
    layout1->setAlignment(Qt::AlignHCenter); //布局中各窗体的显示位置
    layout1->addWidget(toolButton1_1);
    layout1->addWidget(toolButton1_2);
    layout1->addWidget(toolButton1_3);
    layout1->addWidget(toolButton1_4);
    layout1->addWidget(toolButton1_5);
    layout1->addStretch(); //插入一个占位符


    toolButton2_1 = new  QToolButton ;
    toolButton2_1->setText(tr("yun"));
    toolButton2_1->setIcon(QPixmap(""));
    toolButton2_1->setIconSize(QPixmap("").size());
    toolButton2_1->setAutoRaise(true);
    toolButton2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    toolButton2_2 = new  QToolButton ;
    toolButton2_2->setText(tr("yu"));
    toolButton2_2->setIcon(QPixmap(""));
    toolButton2_2->setIconSize(QPixmap("").size());
    toolButton2_2->setAutoRaise(true);
    toolButton2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    QGroupBox *groupBox2 = new QGroupBox ;
    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);

    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolButton2_1);
    layout2->addWidget(toolButton2_2);

    toolButton3_1 = new  QToolButton ;
    toolButton3_1->setText(tr("hui"));
    toolButton3_1->setIcon(QPixmap(""));
    toolButton3_1->setIconSize(QPixmap("").size());
    toolButton3_1->setAutoRaise(true);
    toolButton3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    toolButton3_2 = new  QToolButton ;
    toolButton3_2->setText(tr("lai"));
    toolButton3_2->setIcon(QPixmap(""));
    toolButton3_2->setIconSize(QPixmap("").size());
    toolButton3_2->setAutoRaise(true);
    toolButton3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置工具按钮的文本在图标之外

    QGroupBox *groupBox3 = new QGroupBox ;
    QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);

    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignHCenter);
    layout3->addWidget(toolButton3_1);
    layout3->addWidget(toolButton3_2);

    this->addItem((QWidget *)groupBox1,tr("我的好友"));
    this->addItem((QWidget *)groupBox2,tr("陌生人"));
    this->addItem((QWidget *)groupBox3,tr("黑名单"));

}
