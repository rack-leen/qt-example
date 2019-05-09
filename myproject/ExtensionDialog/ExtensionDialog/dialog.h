#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void showDetailInfor(); //点击详细按钮显示详细信息

private:
    void createBaseInfor(); //创建基本对话窗体部分，用Widget实现
    void createDetailInfor(); //创建详细信息窗口部分

    QWidget *baseWidget ;
    QWidget *detailWidget ;
};

#endif // DIALOG_H
