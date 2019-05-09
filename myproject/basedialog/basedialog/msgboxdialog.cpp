#include "msgboxdialog.h"

MsgBoxDialog::MsgBoxDialog(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("标准消息对话框实例"));

    label = new QLabel ;
    label->setText(tr("请选择一种消息框"));

    questionButton = new QPushButton ;
    questionButton->setText(tr("Question"));

    informationButton = new QPushButton ;
    informationButton->setText(tr("Information"));

    warningButton = new QPushButton ;
    warningButton->setText(tr("Warning"));

    criticalButton = new QPushButton ;
    criticalButton->setText(tr("Critical"));

    aboutButton = new   QPushButton ;
    aboutButton->setText(tr("About"));

    aboutQtButton = new QPushButton ;
    aboutQtButton->setText(tr("AboutQt"));

    mainLayout = new QGridLayout(this) ;

    mainLayout->addWidget(label , 0,0,1,2);
    mainLayout->addWidget(questionButton,1,0);
    mainLayout->addWidget(informationButton,1,1);
    mainLayout->addWidget(warningButton,2,0);
    mainLayout->addWidget(criticalButton,2,1);
    mainLayout->addWidget(aboutButton,3,0);
    mainLayout->addWidget(aboutQtButton,3,1);


    connect(questionButton , &QPushButton::clicked , this , &MsgBoxDialog::showQuestionMsg);
    connect(informationButton , &QPushButton::clicked , this , &MsgBoxDialog::showInformationMsg);
    connect(warningButton , &QPushButton::clicked , this , &MsgBoxDialog::showWarningMsg);
    connect(criticalButton , &QPushButton::clicked , this , &MsgBoxDialog::showCriticalMsg);
    connect(aboutButton , &QPushButton::clicked , this , &MsgBoxDialog::showAboutMsg);
    connect(aboutQtButton , &QPushButton::clicked , this , &MsgBoxDialog::showAboutQtMsg);

}

void MsgBoxDialog::showQuestionMsg()
{
    label->setText(tr("Question Messege Box"));
    switch (QMessageBox::question(this,tr("Question消息框"),tr("您现在已经修改完成，是否要退出程序？"),QMessageBox::Ok|QMessageBox::Cancel ,QMessageBox::Ok))
    {
        case QMessageBox::Ok :
                label->setText("Question button/OK");
                break ;
        case QMessageBox::Cancel :
                label->setText("Question button/Cancel");
                break;
    default:
        break;
    }
    return ;

}

void MsgBoxDialog::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this , tr("Information消息框"),tr("Information消息框，欢迎您！"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    return ;

}

void MsgBoxDialog::showWarningMsg()
{
    label->setText(tr("Warning Message Box"));
    switch(QMessageBox::warning(this,tr("Warning消息框"),tr("这是Warning消息框"),QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save))
    {
    case QMessageBox::Save :
        label->setText(tr("Warning button/Save"));
        break;

    case QMessageBox::Discard :
        label->setText(tr("Warning button/Discard"));
        break;

    case QMessageBox::Cancel :
        label->setText(tr("Warning button/Cancel"));

    default:
        break;
    }
    return;


}

void MsgBoxDialog::showCriticalMsg()
{
     label->setText(tr("Critical Message Box"));
     QMessageBox::critical(this , tr("Critical消息框"),tr("这是Critical消息框"));
     return;
}

void MsgBoxDialog::showAboutMsg()
{
     label->setText(tr("About Message Box"));
     QMessageBox::about(this , tr("About消息框"),tr("这是About消息框"));
     return;
}

void MsgBoxDialog::showAboutQtMsg()
{
   label->setText(tr("AboutQt Message Box"));
   QMessageBox::aboutQt(this , tr("About Qt消息框"));
   return;
}
