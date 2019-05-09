#ifndef MSGBOXDIALOG_H
#define MSGBOXDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QMessageBox>

class MsgBoxDialog : public QWidget
{
    Q_OBJECT
public:
    explicit MsgBoxDialog(QWidget *parent = nullptr);

signals:

public slots:
    void showQuestionMsg();
    void showInformationMsg();
    void showWarningMsg();
    void showCriticalMsg();
    void showAboutMsg();
    void showAboutQtMsg();

private:
    QLabel *label ;  //设置大标题
    QPushButton *questionButton ;
    QPushButton *informationButton ;
    QPushButton *warningButton ;
    QPushButton *criticalButton ;
    QPushButton *aboutButton ; //about按钮
    QPushButton *aboutQtButton ; //aboutqt对话框按钮

    QGridLayout *mainLayout ;
};

#endif // MSGBOXDIALOG_H
