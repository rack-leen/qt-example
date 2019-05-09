#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QGridLayout>
#include "inputdialog.h"
#include "msgboxdialog.h"
#include "customdialog.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    void showFile(); //显示文件
    void showColor() ; //显示颜色
    void showFont() ; //显示字体
    void showInputDialog(); //显示标准输入对话框
    void showMsgBoxDialog(); //显示消息对话框
    void showCustomDialog(); //显示自定义消息框

private:

    //标准文件对话框
    QPushButton *fileButton ; //文件按钮
    QLineEdit *fileLineEdit ; //文件行编辑
    QGridLayout *mainLayout ; //网格布局

    //标准颜色对话框
    QPushButton *colorButton ; //颜色按钮
    QFrame *colorFrame ; //颜色框架

    //标准字体对话框
    QPushButton *fontButton ; //字体按钮
    QLineEdit *fontLineEdit ; //字体行编辑

    //标准输入对话框
    QPushButton *inputdialogButton ;
    InputDialog *inputdialog ;

    //消息对话框
    QPushButton *msgBoxButton ;
    MsgBoxDialog *msgBoxDialog ;

    //自定义消息框
    QPushButton *customButton ;
    QLabel *label ;

};

#endif // DIALOG_H
