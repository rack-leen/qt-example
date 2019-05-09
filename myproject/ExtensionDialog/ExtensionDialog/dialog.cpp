#include "dialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QGridLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("ExtensionDialog")); //设置窗口标题

    createBaseInfor(); //创建基本窗口
    createDetailInfor(); //创建详细窗口

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(baseWidget);
    mainLayout->addWidget(detailWidget);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize); //固定尺寸
    mainLayout->setSpacing(10);
}

void Dialog::createBaseInfor()
{
    baseWidget = new QWidget ; //创建基本窗口对象

    QLabel *nameLabel = new QLabel(tr("姓名："));
    QLineEdit *nameLineEdit = new QLineEdit ;

    QLabel *sexLabel = new QLabel(tr("性别："));
    QComboBox *sexComboBox = new QComboBox ;
    sexComboBox->insertItem(0,tr("男"));
    sexComboBox->insertItem(1,tr("女"));
    sexComboBox->insertItem(2,tr("妖"));

    QGridLayout *leftLayout = new QGridLayout ;
    leftLayout->addWidget(nameLabel,0,0);
    leftLayout->addWidget(nameLineEdit,0,1);
    leftLayout->addWidget(sexLabel,1,0);
    leftLayout->addWidget(sexComboBox,1,1);

    QPushButton *okButton = new QPushButton(tr("确定")) ;
    QPushButton *detailButton = new QPushButton(tr("详细")) ;

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Vertical); //按钮盒子使用垂直布局
    buttonBox->addButton(okButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(detailButton,QDialogButtonBox::ActionRole);

    QHBoxLayout *mainLayout = new QHBoxLayout(baseWidget);
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(buttonBox);

    connect(detailButton , &QPushButton::clicked , this , &Dialog::showDetailInfor);

}

void Dialog::createDetailInfor()
{
    detailWidget = new QWidget ; //创建详细窗体部分

    QLabel *ageLabel = new QLabel(tr("年龄："));
    QLineEdit *ageLineEdit = new   QLineEdit ;
    ageLineEdit->setText(tr("18")); //设置默认年龄

    QLabel *departmentLabel = new QLabel(tr("部门："));
    QComboBox *departmentComboBox = new QComboBox ;
    departmentComboBox->addItem(tr("销售部"));
    departmentComboBox->addItem(tr("营销部"));
    departmentComboBox->addItem(tr("市场部"));
    departmentComboBox->addItem(tr("人事部"));
    departmentComboBox->insertItem(4,tr("后勤部")); //两种方法增加都可以

    QLabel *emailLabel = new QLabel(tr("Email:"));
    QLineEdit *emailLineEdit = new QLineEdit ;
    emailLineEdit->setText(tr("1214236547@qq.com"));

    QGridLayout *mainLayout = new QGridLayout(detailWidget);
    mainLayout->addWidget(ageLabel,0,0);
    mainLayout->addWidget(ageLineEdit,0,1);
    mainLayout->addWidget(departmentLabel,1,0);
    mainLayout->addWidget(departmentComboBox,1,1);
    mainLayout->addWidget(emailLabel,2,0);
    mainLayout->addWidget(emailLineEdit,2,1);

    detailWidget->hide();
}

void Dialog::showDetailInfor()
{
    if(detailWidget->isHidden()) //如果detail窗口被隐藏
    {
        detailWidget->show();
    }
    else
    {
        detailWidget->hide() ;
    }
}
Dialog::~Dialog()
{

}
