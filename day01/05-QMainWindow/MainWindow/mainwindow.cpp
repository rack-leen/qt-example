#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar> //菜单栏头文件
#include <QMenu>      //菜单头文件
#include <QAction>    //选项头文件
#include <QDebug>
#include <QToolBar>  //工具栏头文件
#include <QPushButton>
#include <QStatusBar> //状态栏头文件
#include <QLabel> //标签
#include <QTextEdit> //文本编辑区
#include <QDockWidget> //浮动窗口
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //菜单栏
    QMenuBar *mBar = menuBar();
    QMenu *pFile = mBar->addMenu("文件");
   QAction *pNew = pFile->addAction("新建"); //文件按钮
   connect(pNew , &QAction::triggered ,
           [=]()
            {
                    qDebug() << "新建文件按下";
            }
           );
   pFile->addSeparator() ; //分割线
   QAction *pOpen = pFile->addAction("打开"); //打开按钮
   pFile->addSeparator() ; //分割线
   QAction *pSave = pFile->addAction("保存"); //保存按钮
    //工具栏，菜单项的快捷方式
   QToolBar *toolBar = addToolBar("toolBar"); //添加名字为"toolBar"的工具栏
   //添加快捷方式
   toolBar->addAction(pNew); //添加新建按钮的快捷方式

   //将控件添加到工具栏
   QPushButton *b = new QPushButton(this);
   b->setText("love");
   b->move(0,0);
   toolBar->addWidget(b);
   connect(b , &QPushButton::clicked ,
           [=]()
            {
                    b->setText("hate");
            }
           );

   //状态栏
   QStatusBar  *sBar = statusBar(); //获取状态栏
   QLabel *lable = new QLabel(this);
   lable->setText("normal text file");
   sBar->addWidget(lable); //将lable标签中的内容增加到状态栏
   //从左往右添加
   sBar->addWidget(new QLabel("2",this)); //直接分配空间
   //从右往左添加
   sBar->addPermanentWidget(new QLabel("what",this));

   //核心控件
   QTextEdit *textEdit = new QTextEdit(this); //创建文本编辑区
    setCentralWidget(textEdit); //直接可以作为文本编辑器,可以写文本

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this); //创建浮动窗口
    addDockWidget(Qt::RightDockWidgetArea , dock); //将创建的浮动窗口添加进去

    //给浮动窗口添加控件
    QTextEdit *textEdit1 = new QTextEdit(this);
    dock->setWidget(textEdit1);

}

MainWindow::~MainWindow()
{
    delete ui;
}
