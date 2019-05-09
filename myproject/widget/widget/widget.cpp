#include "widget.h"
#include "ui_widget.h"
#include <QListView>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->CollegeCmb->setCurrentIndex(0);
    ui->majorCmb->clear();

    setStyleSheet("QComboBox { min-height: 20px; min-width: 40px; }"
            "QComboBox QAbstractItemView::item { min-height: 20px; min-width: 80px; }");

    ui->CollegeCmb->setView(new QListView());
    ui->majorCmb->setView(new QListView());
    connect(ui->CollegeCmb,SIGNAL(currentIndexChanged(int)),this,SLOT(AttachChose()));
}

void  Widget::AttachChose()
{
    int currentIndex=ui->CollegeCmb->currentIndex();
    switch (currentIndex) {
    case 0:
        ui->majorCmb->clear();
        break;
    case 1:
        ui->majorCmb->clear();
        ui->majorCmb->addItem(tr("机械工程及自动化专业"));
        ui->majorCmb->addItem(tr("机械电子工程"));
        ui->majorCmb->addItem(tr("材料成型及控制工程专业"));
        ui->majorCmb->addItem(tr("过程装备与控制工程专业"));
        break;
    case 2:
        ui->majorCmb->clear();
        ui->majorCmb->addItem(tr("中国语言文学"));
        ui->majorCmb->addItem(tr("汉语言文字学"));
        ui->majorCmb->addItem(tr("语言学及应用语言学"));
        ui->majorCmb->addItem(tr("外国语言文学"));
        break;
    case 3:
        ui->majorCmb->clear();
        ui->majorCmb->addItem(tr("计算机科学与技术"));
        ui->majorCmb->addItem(tr("软件工程"));
        ui->majorCmb->addItem(tr("网络工程"));
        ui->majorCmb->addItem(tr("数字媒体技术专业"));
        break;
    default:
        break;
    }
}

Widget::~Widget()
{
    delete ui;
}
