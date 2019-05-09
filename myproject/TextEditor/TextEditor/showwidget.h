#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H
/*
 * 显示文本编辑框的函数集合
*/
#include <QWidget>
#include <QImage> //图片的头文件
#include <QTextEdit> //文本编辑区域
#include <QLabel>
#include <QHBoxLayout> //文本编辑区使用水平布局


class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = nullptr);
    QImage img ;
    QLabel *imageLabel ; //为插入的图像提供标签
    QTextEdit *mainText ; //主文本编辑区域
signals:

public slots:



};

#endif // SHOWWIDGET_H
