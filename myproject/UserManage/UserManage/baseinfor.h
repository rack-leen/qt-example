#ifndef BASEINFOR_H
#define BASEINFOR_H

#include <QWidget>
#include <QLabel> //标签
#include <QLineEdit> //行编辑
#include <QTextEdit> //文本编辑
#include <QComboBox> //滚动条头文件
#include <QGridLayout> //网格布局
#include <QPushButton>
#include <QHBoxLayout> //平行布局

class BaseInfor : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfor(QWidget *parent = nullptr);

signals:

public slots:

private:
    //左侧
    QLabel *UserNameLabel ; //用户名
    QLabel *NameLabel ; //姓名
    QLabel *SexLabel ; //性别
    QLabel *DepartmentLabel ; //部门
    QLabel *AgeLabel ; //年龄
    QLabel *OtherLabel ; //备注
    QLineEdit *UserNameLineEdit ; //用户名行编辑
    QLineEdit *NameLineEdit ; //姓名行编辑
    QComboBox *SexComboBox ; //性别滚动条
    QTextEdit *DepartmentTextEdit ; //部分用文本编辑
    QLineEdit *AgeLineEdit ; //年龄用行编辑
//    QTextEdit *OtherTextEdit ; //备注用文本编辑
    QGridLayout *LeftLayout ; //左部布局,网格布局

    //右侧
    //右上角
    QLabel *HeadLabel ; //头像文本标签
    QLabel *HeadIconLabel ; //头像图像标签
    QPushButton *HeadUpdate ; //更新更改的头像按钮
    QHBoxLayout *TopRightLayout ; //右上角使用平行布局

    //右下角
    QLabel *IntroductionLabel ; //个人说明
    QTextEdit *IntroductionEdit ; //个人说明使用文本编辑
    QVBoxLayout *RightLayout ; // 右下角使用垂直布局

    //底部
    QPushButton *OkButton ; //ok键
    QPushButton *CancelButton ; //cancel键
    QHBoxLayout *ButtonLayout ; //底部使用平行布局
};

#endif // BASEINFOR_H
