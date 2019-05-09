#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QCheckBox>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *EmailLabel ; //邮件标签
    QLineEdit *EmailLineEdit ; //邮件行编辑
    QLabel *AddrLabel ; //地址标签
    QLineEdit *AddrLineEdit ; //地址行编辑
    QLabel *CodeLabel ; //邮政编码标签
    QLineEdit *CodeLineEdit ; //邮政行编辑
    QLabel *MobTelLabel ; //移动电话
    QLineEdit *MobTelLineEdit ; //移动电话行编辑
    QCheckBox *MobTelCheckBox ; //接收留言
    QLabel *ProTelLabel ; //公共电话标签
    QLineEdit *ProTelLineEdit ; //公共电话行编辑
    QGridLayout *mainLayout ;

};

#endif // CONTACT_H
