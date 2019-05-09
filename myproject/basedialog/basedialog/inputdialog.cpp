#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("标准输入对话框实例"));

    nameLabel1 = new QLabel ;
    nameLabel1->setText(tr("姓名："));
    nameLabel2 = new QLabel ;
    nameLabel2->setText(tr("张三")); //姓名输入的初始值
    nameLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    nameButton = new QPushButton ;
    nameButton->setText(tr("修改姓名"));

    sexLabel1 = new QLabel ;
    sexLabel1->setText(tr("性别："));
    sexLabel2 = new QLabel ;
    sexLabel2->setText(tr("男")); //性别输入的初始值
    sexLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    sexButton = new QPushButton ;
    sexButton->setText(tr("修改性别"));

    ageLabel1 = new QLabel ;
    ageLabel1->setText(tr("年龄："));
    ageLabel2 = new QLabel ;
    ageLabel2->setText(tr("18"));
    ageLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ageButton = new QPushButton ;
    ageButton->setText(tr("修改年龄"));

    scoreLabel1 = new QLabel ;
    scoreLabel1->setText(tr("成绩："));
    scoreLabel2 = new QLabel ;
    scoreLabel2->setText(tr("90"));
    scoreLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    scoreButton = new QPushButton ;
    scoreButton->setText(tr("修改成绩"));

    inputLayout = new QGridLayout(this);
    inputLayout->addWidget(nameLabel1,0,0);
    inputLayout->addWidget(nameLabel2,0,1);
    inputLayout->addWidget(nameButton,0,2);

    inputLayout->addWidget(sexLabel1,1,0);
    inputLayout->addWidget(sexLabel2,1,1);
    inputLayout->addWidget(sexButton,1,2);

    inputLayout->addWidget(ageLabel1,2,0);
    inputLayout->addWidget(ageLabel2,2,1);
    inputLayout->addWidget(ageButton,2,2);

    inputLayout->addWidget(scoreLabel1,3,0);
    inputLayout->addWidget(scoreLabel2,3,1);
    inputLayout->addWidget(scoreButton,3,2);

    inputLayout->setMargin(15);
    inputLayout->setSpacing(10);

    connect(nameButton , &QPushButton::clicked , this , &InputDialog::changeName);
    connect(sexButton , &QPushButton::clicked , this , &InputDialog::changeSex);
    connect(ageButton , &QPushButton::clicked , this , &InputDialog::changeAge);
    connect(scoreButton , &QPushButton::clicked , this , &InputDialog::changeScore);

}

void InputDialog::changeName()
{
    //标准字符串输入
    bool ok ;
    QString text = QInputDialog::getText(this , tr("标准字符串输入对话框"),tr("请输入姓名："),QLineEdit::Normal ,nameLabel2->text(),&ok);
    if(ok && !text.isEmpty())
    {
        nameLabel2->setText(text);
    }

}

void InputDialog::changeSex()
{
    //标准条目选择对话框
    QStringList sexItems ;
    sexItems << "男" << "女" << "人妖" ;

    bool ok ;
    QString sexItem = QInputDialog::getItem(this,tr("标准条目选择对话框"),tr("请输入性别："),sexItems,0,false,&ok);
    if(ok && ! sexItem.isEmpty())
    {
        sexLabel2->setText(sexItem);
    }

}

void InputDialog::changeAge()
{
    //标准整型输入
    bool ok ;
    int age = QInputDialog::getInt(this,tr("标准int类型输入对话框"),tr("请输入年龄："), ageLabel2->text().toInt(&ok) ,0,100,1,&ok);
    if(ok)
    {
        ageLabel2->setText(QString(tr("%1").arg(age))); //将整型转换为字符串
    }
}

void InputDialog::changeScore()
{
    //标准浮点型输入
    bool ok ;
    double score = QInputDialog::getDouble(this,tr("标准double类型输入对话框"),tr("请输入成绩："),scoreLabel2->text().toDouble(&ok),0,100,2,&ok);
    if(ok)
    {
        scoreLabel2->setText(QString(tr("%1")).arg(score));
    }

}
