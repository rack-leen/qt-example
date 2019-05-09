#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void MousePressEvent(QMouseEvent *);
    void MouseMoveEvent(QMouseEvent *);
    void PaintEvent(QPaintEvent * );

private:
    QPoint dragPosition ;
};

#endif // WIDGET_H
