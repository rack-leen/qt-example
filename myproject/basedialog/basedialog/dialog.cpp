#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    //文件对话框
    fileButton = new QPushButton ;
    fileButton->setText(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit ;
    mainLayout = new QGridLayout(this);

    mainLayout->addWidget(fileButton,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);

    connect(fileButton , &QPushButton::clicked , this , &Dialog::showFile);


    //颜色对话框
    colorButton = new QPushButton ;
    colorButton->setText("颜色标准对话框实例");
    colorFrame = new QFrame ;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true); //设置自动填充背景

    mainLayout->addWidget(colorButton,1,0);
    mainLayout->addWidget(colorFrame,1,1);

    connect(colorButton , &QPushButton::clicked , this , &Dialog::showColor);

    //字体对话框
    fontButton = new QPushButton ;
    fontButton->setText(tr("字体标准对话框实例"));
    fontLineEdit = new QLineEdit ;
    fontLineEdit->setText(tr("Welcome !"));

    mainLayout->addWidget(fontButton,2,0);
    mainLayout->addWidget(fontLineEdit,2,1);

    connect(fontButton , &QPushButton::clicked , this , &Dialog::showFont);

    //标准输入对话框
    inputdialogButton = new QPushButton ;
    inputdialogButton->setText(tr("标准输入对话框实例"));

    mainLayout->addWidget(inputdialogButton,3,0);

    connect(inputdialogButton , &QPushButton::clicked , this , &Dialog::showInputDialog);

    //消息对话框
    msgBoxButton = new QPushButton ;
    msgBoxButton->setText(tr("标准消息对话框实例"));

    mainLayout->addWidget(msgBoxButton,3,1);

    connect(msgBoxButton , &QPushButton::clicked , this , &Dialog::showMsgBoxDialog);

    //自定义消息框
    customButton = new QPushButton ;
    customButton->setText(tr("自定义消息框"));

    label = new QLabel ;
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);


    mainLayout->addWidget(customButton,4,0);
    mainLayout->addWidget(label,4,1);

    connect(customButton , &QPushButton::clicked , this , &Dialog::showCustomDialog);


}

void Dialog::showFile()
{
    QString s = QFileDialog::getOpenFileName(this , tr("Open fileDialog"),"/",tr("C++ files(*.cpp);;C files(*.c)" ));
    fileLineEdit->setText(s);
}

void Dialog::showColor()
{
    QColor c = QColorDialog::getColor(Qt::blue); //得到蓝色
    if(c.isValid()) //如果这个颜色是有效的
    {
        colorFrame->setPalette(QPalette(c)); //调用系统调色板设置颜色
    }
}

void Dialog::showFont()
{
    bool ok ;
    QFont f = QFontDialog::getFont(&ok); //调用系统字体
    if(ok)
    {
        fontLineEdit->setFont(f);
    }
}

void Dialog::showInputDialog()
{
    inputdialog = new InputDialog(); //新建一个InputDialog对象
    inputdialog->show();
}

void Dialog::showMsgBoxDialog()
{
    msgBoxDialog = new MsgBoxDialog() ;
    msgBoxDialog->show();
}

void Dialog::showCustomDialog()
{
      label->setText(tr("Custom Message Box"));

      QMessageBox customMsgBox ;
      customMsgBox.setWindowTitle(tr("用户自定义消息框"));

      QPushButton *yesButton = customMsgBox.addButton(tr("yes"),QMessageBox::ActionRole);
      QPushButton *noButton = customMsgBox.addButton(tr("no"),QMessageBox::ActionRole);
      QPushButton *cancelButton = customMsgBox.addButton(QMessageBox::Cancel);

      customMsgBox.setText(tr("这是一个用户自定义消息框"));
      customMsgBox.setIconPixmap(QPixmap(""));
      customMsgBox.exec();

      if(customMsgBox.clickedButton() == yesButton)
      {
          label->setText(tr("Custom Message Box/yes"));
      }

      if(customMsgBox.clickedButton() == noButton)
      {
          label->setText(tr("Custom Message Box/no"));
      }

      if(customMsgBox.clickedButton() == cancelButton)
      {
          label->setText(tr("Custom Message Box/cancel"));
      }

      return;
}



Dialog::~Dialog()
{

}
