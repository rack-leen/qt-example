#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QToolBox>
#include <QToolButton>
#include "drawer.h"


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:

};

#endif // DIALOG_H
