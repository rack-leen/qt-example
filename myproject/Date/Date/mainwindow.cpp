#include "mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(490,370);
       this->centralWidget();

       QDate dt1 = QDate(1994,10,13);
       QDate dt2 = QDate::currentDate();

       dateEdit[0] = new QDateEdit(dt1.addYears(2),this);
       dateEdit[0]->setGeometry(10,10,140,40);

       dateEdit[1] = new QDateEdit(dt1.addMonths(2),this);
       dateEdit[1]->setGeometry(160,10,140,40);

       dateEdit[2] = new QDateEdit(dt1.addDays(2),this);
       dateEdit[2]->setGeometry(310,10,140,40);

       dateEdit[3] = new QDateEdit(dt2,this);
       dateEdit[3]->setGeometry(10,60,140,40);

       // 判断日期是否合法1
       if(QDate::isValid(2016,02,30))
       {
           qDebug()<<"2016-02-30是合法日期";
       }
       else
       {
           qDebug()<<"2016-02-30是非法日期";
       }
       // 判断日期是否合法2
       if(QDate(2016,02,21).isValid())
       {
           qDebug()<<"2016-02-21是合法日期";
       }
       else
       {
           qDebug()<<"2016-02-21是非法日期";
       }
       // 从字符串格式化得到日期
       QDate dt3 = QDate::fromString("2016.02.01","yyyy.MM.dd");
       QDate dt4 = QDate::fromString("02-01","MM-dd");
       qDebug()<<"字符串1格式化得到的时间"<<dt3.toString();
       qDebug()<<"字符串2格式化得到的时间"<<dt4.toString();
       // 将时间转化为字符串
       qDebug()<<"TextDate格式（默认）："<<dt3.toString(Qt::TextDate);
       qDebug()<<"ISO格式："<<dt3.toString(Qt::ISODate);
       qDebug()<<"各国表现方式："<<dt3.toString(Qt::SystemLocaleDate);
       connect(dateEdit[3],SIGNAL(dateChanged(QDate)),this,SLOT(dateChanged()));
       // 得到星期，月的长短英文字符串
       QString longWeek = dt3.longDayName(dt3.dayOfWeek());
       QString longMonth = dt3.longMonthName(dt3.month());
       QString strDateLong = QString("%1 %2").arg(longWeek).arg(longMonth);

       QString shortWeek = dt3.longDayName(dt3.dayOfWeek());
       QString shortMonth = dt3.longMonthName(dt3.month());
       QString strDateShort = QString("%1 %2").arg(shortWeek).arg(shortMonth);

       qDebug()<<"短名称"<<strDateShort;
       qDebug()<<"长名称"<<strDateLong;
}

MainWindow::~MainWindow()
{

}

void MainWindow::dateChanged()
{
    QDate dt = dateEdit[3]->date();
    // 显示星期
    switch (dt.dayOfWeek()) {
    case 1:
        qDebug()<<"星期一,"<<"今年第"<<dt.dayOfYear()<<"天";
        qDebug()<<"该月总共"<<dt.daysInMonth()<<"天，改年总共"<<dt.daysInYear()<<"天";
        break;
    case 2:
        qDebug()<<"星期二,"<<"今年第"<<dt.dayOfYear()<<"天";
        qDebug()<<"该月总共"<<dt.daysInMonth()<<"天，改年总共"<<dt.daysInYear()<<"天";
        break;
    case 3:
        qDebug()<<"星期三,"<<"今年第"<<dt.dayOfYear()<<"天";
        qDebug()<<"该月总共"<<dt.daysInMonth()<<"天，改年总共"<<dt.daysInYear()<<"天";
        break;
    case 4:
        qDebug()<<"星期四,"<<"今年第"<<dt.dayOfYear()<<"天";
        qDebug()<<"该月总共"<<dt.daysInMonth()<<"天，改年总共"<<dt.daysInYear()<<"天";
        break;
    case 5:
        qDebug()<<"星期五,"<<"今年第"<<dt.dayOfYear()<<"天";
        qDebug()<<"该月总共"<<dt.daysInMonth()<<"天，改年总共"<<dt.daysInYear()<<"天";
        break;
    case 6:
        qDebug()<<"星期六,"<<"今年第"<<dt.dayOfYear()<<"天";
        qDebug()<<"该月总共"<<dt.daysInMonth()<<"天，改年总共"<<dt.daysInYear()<<"天";
        break;
    case 7:
        qDebug()<<"星期七,"<<"今年第"<<dt.dayOfYear()<<"天";
        qDebug()<<"该月总共"<<dt.daysInMonth()<<"天，改年总共"<<dt.daysInYear()<<"天";
        break;
    default:
        break;
    }
}
