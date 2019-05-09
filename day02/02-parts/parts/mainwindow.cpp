#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter> //字符模板
#include <QStringList> //字符串列表
#include <QMovie> //加入动画

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str = ui->lineEdit->text();
    qDebug() << str ;

    //设置内容
    ui->lineEdit->setText("asfdsghf");

    //设置内容显示间隙
    ui->lineEdit->setTextMargins(15,0,0,0);

    //设置内容显示方式
    //ui->lineEdit->setEchoMode(QLineEdit::Password); //设置密码显示方式

    QStringList list ;
    list << "hello" << "How are you" << "hehe"; //设置三个模板
    QCompleter *com = new QCompleter(list , this); //将字符列表传进模板
    com->setCaseSensitivity(Qt::CaseInsensitive); //不区分大小写敏感
    ui->lineEdit->setCompleter(com); //输入不完全的字符显示多个可能需要的字符

    //QLable
    //设置内容
    ui->labelText->setText("my contury");
    //设置图片
    ui->labelImage->setPixmap(QPixmap("://2.svg"));
    ui->labelImage->setScaledContents(true);

    //设置动画，加入Qmovie头文件
    QMovie *myMovie = new QMovie("");
    myMovie->start(); //启动动画
    ui->labelGif->setScaledContents(true);

    //设置链接
    ui->labelUrl->setText("<h1><a href=https://www.baidu.com>百度一下</a></h1>");
    ui->labelUrl->setOpenExternalLinks(true); //用浏览器打开外部链接
    ui->labelUrl->setScaledContents(true);

    //LCD
    ui->lcdNumber->display(123); //用数码管显示数字

    //进度条
    ui->progressBar->setMinimum(0); //设置最小值
    ui->progressBar->setMaximum(200); //设置最大值
    ui->progressBar->setValue(100); //设置当前值

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{
    static int i = 0 ;

    ui->stackedWidget->setCurrentIndex(++i % 4); //如果达到四页就从头再来
}
