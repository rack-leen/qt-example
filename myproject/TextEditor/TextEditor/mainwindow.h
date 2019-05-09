#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMenu> //菜单
#include <QMenuBar> //菜单栏
#include <QToolBox> //工具盒
#include <QToolBar> //工具栏
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QFontComboBox>
#include <QToolButton>
#include <QTextCharFormat>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QtPrintSupport/QPrinter> //打印机
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include <QImage>
#include "showwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createActions(); //创建动作
    void createMenus(); //创建菜单栏
    void createToolBars(); //创建工具栏

    void loadFile(QString filename);
    void mergeFormat(QTextCharFormat);

private slots:

    //文件菜单栏
    void showOpenFile(); //打开文件
    void showNewFIle(); //新建文件
    void showPrintText(); //打印文本
    void showPrintImage(); //打印图片


    //编辑菜单栏
    void showZoomIn(); //放大图片
    void showZoomOut();//缩小图片

    //旋转菜单栏
    void showRotate90();
    void showRotate180();
    void showRotate270();

    //镜像菜单栏
    void showMirrorVertical();
    void showMirrorHorizontal();

    //关于菜单栏
    void showAbout();

private:
    //菜单栏
    QMenu *fileMenu ; //文件菜单
    QMenu *editMenu ; //编辑菜单
    QMenu *rotateMenu; //旋转菜单
    QMenu *mirrorMenu; //镜像菜单
    QMenu *aboutMenu ; //关于菜单

    QString filename;
    QImage img ;  //插入的图像

    ShowWidget *showWidget ;
    //菜单项

    //文件菜单项
    QAction *openFileAction ; //打开文件
    QAction *newFileAction ; //新建文件
    QAction *printTextAction ; //打印文本
    QAction *printImageAction ; //打印图像
    QAction *exitAction ; //退出

    //编辑菜单项
    QAction *copyAction ; //复制
    QAction *cutAction ; //剪切
    QAction *pasteAction ;//粘贴
    QAction *undoAction ; //撤销
    QAction *redoAction ; //返回
    QAction *zoomInAction ; //放大
    QAction *zoomOutAction ; //缩小

    //旋转菜单项
    QAction *rotate90Action ; //旋转90度
    QAction *rotate180Action ; //旋转180
    QAction *rotate270Action ; //旋转270

    //镜像菜单项
    QAction *mirrorVerticalAction ; //镜像垂直
    QAction *mirrorHorizontalAction ; //镜像平行


    //关于菜单项
    QAction *aboutQtAction ;
    QAction *aboutAction ; //关于


    //工具栏
    QToolBar *fileTool ; //文件工具
    QToolBar *editTool ; //编辑工具
    QToolBar *rotateTool ; //旋转工具
    QToolBar *mirrorTool ; //镜像工具

    QToolBar *doToolBar ;

};

#endif // MAINWINDOW_H
