#include "mainwindow.h"
#include <QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("My TextEditor"));

    showWidget = new ShowWidget(this) ;
    setCentralWidget(showWidget);//将文本编辑区放在中心部分

    createActions() ; //创建动作
    createMenus() ; //创建菜单
    createToolBars(); //创建工具栏

    if(img.load(":/1.png"))
    {
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
        qDebug()<<"OK!";
    }
    else
    {
        qDebug()<<"NO!";
    }

}

void MainWindow::createActions()
{
    /*******************文件菜单************************/

    //打开文件
    openFileAction = new QAction(tr("打开"),this) ;
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("打开一个文件"));
    connect(openFileAction , &QAction::triggered , this,&MainWindow::showOpenFile);

    //新建文件
    newFileAction = new QAction(tr("新建"),this);
    newFileAction->setShortcut(tr("Ctrl+N"));
    newFileAction->setStatusTip(tr("新建一个文件"));
    connect(newFileAction , &QAction::triggered , this , &MainWindow::showNewFIle);

    //打印文件
    printTextAction = new QAction(tr("打印文件"),this);
    printTextAction->setShortcut(tr("Ctrl+P"));
    printTextAction->setStatusTip(tr("打印一个文件"));
    connect(printTextAction , &QAction::triggered,this , &MainWindow::showPrintText);

    //打印图像
    printImageAction = new QAction(tr("打印图像"),this);
    printImageAction->setShortcut(tr("Ctrl+p"));
    printImageAction->setStatusTip(tr("打印一个图像"));
    connect(printImageAction , &QAction::triggered,this,&MainWindow::showPrintImage);

    //退出程序
    exitAction = new QAction(tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction , &QAction::triggered,this,& MainWindow::close);

    /*******************编辑菜单************************/
    //复制
    copyAction = new QAction(tr("复制"),this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("将一个东西复制"));
    connect(copyAction ,SIGNAL(triggered()),showWidget->mainText,SLOT(copy()));

    //剪切
    cutAction = new QAction(tr("剪切"),this);
    cutAction->setShortcut(tr("Ctrl+X"));
    connect(cutAction,SIGNAL(triggered()),showWidget->mainText,SLOT(cut()));

    //粘贴
    pasteAction = new QAction(tr("粘贴"),this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    connect(pasteAction , SIGNAL(triggered()),showWidget->mainText,SLOT(paste()));

    //撤销
    undoAction = new QAction(tr("撤销"),this);
    connect(undoAction , SIGNAL(triggered()),showWidget->mainText,SLOT(undo()));

    //恢复
    redoAction = new QAction(tr("恢复"),this);
    connect(redoAction , SIGNAL(triggered()),showWidget->mainText,SLOT(redo()));

    //放大
    zoomInAction = new  QAction(tr("放大"),this);
    zoomInAction->setStatusTip(tr("放大一张图片"));
    connect(zoomInAction , &QAction::triggered,this ,&MainWindow::showZoomIn);

    //缩小
    zoomOutAction = new QAction(tr("缩小"),this);
    zoomOutAction->setStatusTip(tr("缩小一张图片"));
    connect(zoomOutAction , &QAction::triggered,this,&MainWindow::showZoomOut);

   /*******************旋转菜单************************/

    //旋转90度
    rotate90Action = new QAction(tr("旋转90度"),this);
    rotate90Action->setStatusTip(tr("将一幅图旋转90度"));
    connect(rotate90Action , &QAction::triggered,this,&MainWindow::showRotate90);

    //旋转180度
    rotate180Action = new QAction(tr("旋转180度"),this);
    rotate180Action->setStatusTip(tr("将一幅图旋转180度"));
    connect(rotate180Action , &QAction::triggered,this,&MainWindow::showRotate180);

    //旋转270度
    rotate270Action = new QAction(tr("旋转260度"),this);
    rotate270Action->setStatusTip(tr("将一幅图旋转270度"));
    connect(rotate270Action , &QAction::triggered,this,&MainWindow::showRotate270);



   /*******************镜像菜单************************/

    //纵向镜像
    mirrorVerticalAction = new QAction(tr("纵向镜像"),this);
    mirrorVerticalAction->setStatusTip(tr("对一张图做纵向镜像"));
    connect(mirrorVerticalAction , &QAction::triggered,this,&MainWindow::showMirrorVertical);

    //横向镜像
    mirrorHorizontalAction = new QAction(tr("横向镜像"),this);
    mirrorHorizontalAction->setStatusTip(tr("对一张图做横向镜像"));
    connect(mirrorHorizontalAction , &QAction::triggered,this,&MainWindow::showMirrorHorizontal);



   /*******************关于菜单************************/
    //关于
    aboutAction = new QAction(tr("关于"),this);
    connect(aboutAction , &QAction::triggered , this , &MainWindow::showAbout);
    //关于Qt
    aboutQtAction = new QAction(tr("关于Qt"),this);
    connect(aboutQtAction , &QAction::triggered,this,&QApplication::aboutQt);
}

void MainWindow::createMenus()
{
    //文件菜单
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(printTextAction);
    fileMenu->addAction(printImageAction);
    fileMenu->addAction(exitAction);


    //编辑菜单
    editMenu = menuBar()->addMenu(tr("编辑"));
    editMenu->addAction(copyAction);
    editMenu->addAction(cutAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addAction(zoomInAction);
    editMenu->addAction(zoomOutAction);

    //旋转菜单
    rotateMenu = menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    //镜像菜单
    mirrorMenu = menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);

    //关于菜单
    aboutMenu = menuBar()->addMenu(tr("关于"));
    aboutMenu->addAction(aboutAction);
    aboutMenu->addAction(aboutQtAction);


}

void MainWindow::createToolBars()
{
    //文件工具条
    fileTool = addToolBar(tr("File"));
    fileTool->addAction(openFileAction);
    fileTool->addAction(newFileAction);
    fileTool->addAction(printTextAction);
    fileTool->addAction(printImageAction);

    //编辑工具条


}

/********************文件菜单栏槽函数****************************/
void MainWindow::showOpenFile()
{
    filename = QFileDialog::getOpenFileName(this,tr("打开文件"),tr("/home/"),tr("All(*.*)"));
    //showWidget->mainText->setText(open); //打开文件路径
    if(!filename.isEmpty())
    {
        //如果原窗口为空白，则在原窗口打开
        if(showWidget->mainText->document()->isEmpty())
        {
            loadFile(filename);
        }
        else  //否则新建一个窗口打开
        {
           MainWindow *newMainWindow = new MainWindow ;
           newMainWindow->show();
           newMainWindow->loadFile(filename);
        }
    }
}

void MainWindow::showNewFIle()
{
    MainWindow *newMainWindow = new MainWindow ;
    newMainWindow->show();
}


void MainWindow::showPrintText()
{
/*
    QPrinter printer  ; //新建打印机对象
    QPrintDialog printDialog(&printer,this); //新建一个printDialog对象

    if(!printDialog.exec())
    {
        QTextDocument *doc = showWidget->mainText->document(); //获得文档
        doc->print(&printer); //将文档给打印机对象打印
    }
*/
}


void MainWindow::showPrintImage()
{
    /*
    QPrinter printer ;
    QPrintDialog printDialog(&printer,this);

    if(!printDialog.exec())
    {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = img.size();
        size.scale(rect.size(),Qt::KeepAspectRatio);

        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);

    }
    */
}

/********************编辑菜单栏槽函数****************************/
void MainWindow::showZoomIn()
{
    if(img.isNull())//判定图片是否存在
    {
        return;
    }
    QMatrix matrix ;
    matrix.scale(2,2); //两倍比例
    img = img.transformed(matrix); //将两倍比例转化为图片的比例
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img)); //将其传到图片上
}

void MainWindow::showZoomOut()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix ;
    matrix.scale(0.5,0.5);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

/********************旋转菜单栏槽函数****************************/
void MainWindow::showRotate90()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix ;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showRotate180()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix ;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showRotate270()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix ;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

/********************镜像菜单栏槽函数****************************/
void MainWindow::showMirrorVertical()
{
    if(img.isNull())
    {
        return;
    }
    img = img.mirrored(false,true);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showMirrorHorizontal()
{
    img = img.mirrored(true,false);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

/********************关于菜单栏槽函数****************************/
void MainWindow::showAbout()
{
    int ret = QMessageBox::question(this,tr("About ?"),tr("This is a TextEditor."),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);

    switch (ret)
    {
    case QMessageBox::Ok :
        qDebug() << "I am Ok !" ;
        break;
    case QMessageBox::Cancel :
        qDebug() << "No , thanks.";
        break;
    default:
        break;
    }
}

void MainWindow::loadFile(QString filename)
{
    //printf("file name: %s\n",filename.data());

    QFile file(filename);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream textStream(&file);
        while (!textStream.atEnd()) //如果文本流没有结束
        {
           showWidget->mainText->append(textStream.readLine());
           printf("read line\n");
        }
        printf("end\n");
    }
}

MainWindow::~MainWindow()
{

}
