#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog> //模式或非模式对话框
#include <QDebug>
#include <QMessageBox> //标准对话框
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *pFile = mBar->addMenu("对话框");
    QAction *pNew = pFile->addAction("模态对话框");
    connect(pNew , &QAction::triggered ,
                []()
                {
                    QDialog dlg ;
                    dlg.exec();
                    qDebug() << "1111";
                }
            );

    QAction *pNew1 = pFile->addAction("非模态对话框");
    connect(pNew1 , &QAction::triggered ,
                [=]()
                {
                    //QDialog dia ;
                    // dia.show();
                    // 这样只能闪现，并不能长存，需要用全局变量或动态内存分配

                    //全局变量
                    //需要将变量在头文件定义

                    //动态分配内存
                    //但是动态分配内存会在程序结束后释放，不能多次操作
                    //QDialog *p = new QDialog(this);
                    //p->show();

                    QDialog *p = new QDialog(this);
                    p->setAttribute(Qt::WA_DeleteOnClose); //在这次操作结束后释放，解决了动态分配内存的缺点
                    p->show();
                    qDebug() << "222";


                }
                );

    QAction *pNew2 = pFile->addAction("关于对话框");
    connect(pNew2 , &QAction::triggered ,
            [=]()
            {
                QMessageBox::about(this , "about","关于qt");
            });

    QAction *pNew3 = pFile->addAction("问题对话框");
    connect(pNew3 , &QAction::triggered ,
            [=]()
            {
            //自定义
                int ret = QMessageBox::question(this , "question" , "Are you ok ?" , QMessageBox::Ok | QMessageBox::Cancel);
                switch(ret)
                {
                    case QMessageBox::Ok :
                            qDebug() << "i am ok !" ;
                    break;
                    case QMessageBox::Cancel :
                            qDebug() << "on , thanks !" ;
                    break;
                default:
                    break;
                }
            });
    QAction *pNew4 = pFile->addAction("文件对话框");
    connect(pNew4 , &QAction::triggered ,
            [=]()
            {
                    QString path = QFileDialog::getOpenFileName(
                                this ,
                                "open", //对话框的标题
                                "./", //打开的文件路径
                                tr("Images (*.png *.xpm *.jpg) ;; source(*.cpp *.h *.c *.cc) ;; Text(*.txt);; all(*.*)")
                                );

                    qDebug() << path ;
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}
