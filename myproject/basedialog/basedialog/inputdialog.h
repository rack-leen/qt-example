#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QInputDialog> //标准输入，包括字符串输入
#include <QStringList>

class InputDialog : public QWidget
{
    Q_OBJECT
public:
    explicit InputDialog(QWidget *parent = nullptr);

signals:

public slots:
    void changeName();
    void changeSex();
    void changeAge();
    void changeScore();

private:
    QLabel *nameLabel1 ;
    QLabel *sexLabel1 ;
    QLabel *ageLabel1 ;
    QLabel *scoreLabel1 ;
    QLabel *nameLabel2 ; //输入姓名
    QLabel *sexLabel2 ; //输入性别
    QLabel *ageLabel2 ; //输入年龄
    QLabel *scoreLabel2 ; //输入成绩

    QPushButton *nameButton ;
    QPushButton *sexButton ;
    QPushButton *ageButton ;
    QPushButton *scoreButton ;

    QGridLayout *inputLayout ;
};

#endif // INPUTDIALOG_H
