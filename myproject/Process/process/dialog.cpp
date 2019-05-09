#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    fileNum = new QLabel ;
    fileNum->setText(tr("文件数目："));

    fileNumLineEdit = new QLineEdit ;
    fileNumLineEdit->setText(tr("100000")); //初始值


    ProcessType = new QLabel ;
    ProcessType->setText(tr("显示类型："));
    comboBox = new QComboBox ; //增加选择条目
    comboBox->addItem(tr("ProcessBar"));
    comboBox->addItem(tr("ProcessDialog"));

    processBar = new QProgressBar ;

    startButton = new QPushButton ;
    startButton->setText(tr("开始"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileNum,0,0);
    mainLayout->addWidget(fileNumLineEdit,0,1);
    mainLayout->addWidget(ProcessType,1,0);
    mainLayout->addWidget(comboBox,1,1);
    mainLayout->addWidget(processBar,2,0,1,2);
    mainLayout->addWidget(startButton,3,1);

    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(startButton , &QPushButton::clicked , this , &Dialog::startProcess);

}

void Dialog::startProcess()
{
    bool ok ;

    int num = fileNumLineEdit->text().toInt(&ok); //行编辑中的文件数目转换为整型

    if(comboBox->currentIndex() == 0) //选择条目的现在的索引为0时,选择第一个,processBar
    {
        //设定进度条范围
        processBar->setRange(0,num);
        for(int i=0 ; i<=num ; i++)
        {
            processBar->setValue(i); //值一个个的增加
        }
    }
    else if(comboBox->currentIndex() == 1) //索引值为1表示现在选择processDialog
    {
        QProgressDialog *processDialog = new QProgressDialog(this) ;
        //QFont font("",12);
        //processDialog->setFont(font);
        processDialog->setWindowModality(Qt::WindowModal); //设置窗口模式
        processDialog->setMinimumDuration(5); //设置延迟
        processDialog->setWindowTitle(tr("Please Wait")); //设置窗口标题
        processDialog->setLabelText(tr("Copy...")); //设置大标题
        processDialog->setCancelButtonText(tr("Cancel")); //设置取消进度条的按钮文本
        processDialog->setRange(0,num);

        for(int i ; i<=num ; i++)
        {
            processDialog->setValue(i);
            //如果取消
            if(processDialog->wasCanceled())
            {
                return ; //直接返回
            }
        }
    }
}

Dialog::~Dialog()
{

}
