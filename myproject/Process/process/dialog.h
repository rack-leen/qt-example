#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QProgressDialog>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void startProcess(); //显示滚动的进度条
private:
    QLabel *fileNum ; //文件数目
    QLineEdit *fileNumLineEdit ; //文件数目行编辑
    QLabel *ProcessType ; //显示类型
    QComboBox *comboBox ; //显示类型后面的选择条目
    QProgressBar *processBar ; //进度条
    QPushButton *startButton ; //进度条的开始按钮
    QGridLayout *mainLayout ;


};

#endif // DIALOG_H
