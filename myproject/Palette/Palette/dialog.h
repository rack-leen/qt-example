#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    void createCtrlFrame(); //创建左边颜色选择区域，这个函数将右边所有东西包含进去
    void createContentFrame(); //创建右边区域
    void fillColorList(QComboBox *); //颜色下拉选框中插入颜色

private slots:
    void showWindow();
    void showWindowText();
    void showButton();
    void showButtonText();
    void showBase();

private:
    //左边
    QFrame *ctrlFrame ; //创建左边区域框架
    QLabel *windowLabel ; //窗口标签
    QComboBox *windowComboBox ;
    QLabel *windowTextLabel ;
    QComboBox *windowTextComboBox ;
    QLabel *buttonLabel ;
    QComboBox *buttonComboBox ;
    QLabel *buttonTextLabel ;
    QComboBox *buttonTextComboBox;
    QLabel *baseLabel ;
    QComboBox *baseComboBox ;

    //右边
    QFrame *contentFrame ; //具体显示面板
    QLabel *label1 ;
    QComboBox *label1ComboBox ;

    QLabel *label2 ;
    QLineEdit *label2LineEdit ;

    QTextEdit *textEdit ;

    QPushButton *okButton ;
    QPushButton *cancelButton ;
};

#endif // DIALOG_H
