#ifndef CONTENT_H
#define CONTENT_H

#include <QDialog>
#include <QStackedWidget>
#include <QPushButton>
#include "baseinfor.h"
#include "contact.h"
#include "detail.h"

class Content : public QFrame
{
    Q_OBJECT

public:
    Content(QWidget *parent = 0);
    ~Content();

    QStackedWidget *stack ;
    QPushButton *AmendButton ;
    QPushButton *CloseButton ;

    BaseInfor *baseinfor ;
    Contact *contact ;
    Detail *detail ;
};

#endif // CONTENT_H
