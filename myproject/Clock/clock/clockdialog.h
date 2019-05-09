#ifndef CLOCKDIALOG_H
#define CLOCKDIALOG_H

#include <QLCDNumber>


class ClockDialog : public QLCDNumber
{
public:
    ClockDialog(QWidget *parent=0);

    void MousePressEvent(QMouseEvent *); //鼠标按下动作
    void MouseMoveEvent(QMouseEvent *); //鼠标拖拽移动动作

private slots:
    void showTime(); //显示当前时间

private:
    QPoint dragPosition ; //保存鼠标点相对电子时钟窗体的左上角的偏移值
    bool showColon ; //显示时间时是否显示“:”
};

#endif // CLOCKDIALOG_H
