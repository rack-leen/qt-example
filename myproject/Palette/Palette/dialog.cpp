#include "dialog.h"
#include <QGridLayout>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(contentFrame);
}

void Dialog::createCtrlFrame()
{
    ctrlFrame = new QFrame ;

    windowLabel = new QLabel(tr("QPalette::Window: "));
    windowComboBox = new QComboBox ;
    fillColorList(windowComboBox); //在下拉选框中插入颜色
    connect(windowComboBox , static_cast<void(QComboBox::*)(int)>(&QComboBox::activated) , this , &Dialog::showWindow);

    windowTextLabel = new QLabel(tr("QPalette::WindowText: "));
    windowTextComboBox = new QComboBox ;
    fillColorList(windowTextComboBox);
    connect(windowTextComboBox , static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),this , &Dialog::showWindowText);

    buttonLabel = new QLabel(tr("QPalette::Button: "));
    buttonComboBox = new QComboBox ;
    fillColorList(buttonComboBox);
    connect(buttonComboBox , static_cast<void(QComboBox::*)(int)>(&QComboBox::activated) ,this , &Dialog::showButton);

    buttonTextLabel = new QLabel(tr("QPalette::ButtonText: "));
    buttonTextComboBox = new QComboBox ;
    fillColorList(buttonTextComboBox);
    connect(buttonTextComboBox , static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),this,&Dialog::showButtonText);


    baseLabel =new QLabel(tr("QPalette::Base: "));
    baseComboBox = new QComboBox ;
    fillColorList(baseComboBox);
    connect(baseComboBox , static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),this,&Dialog::showBase);


    QGridLayout *mainLayout = new QGridLayout(ctrlFrame);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(windowLabel,0,0);
    mainLayout->addWidget(windowComboBox,0,1);

    mainLayout->addWidget(windowTextLabel,1,0);
    mainLayout->addWidget(windowTextComboBox,1,1);

    mainLayout->addWidget(buttonLabel,2,0);
    mainLayout->addWidget(buttonComboBox,2,1);

    mainLayout->addWidget(buttonTextLabel,3,0);
    mainLayout->addWidget(buttonTextComboBox,3,1);

    mainLayout->addWidget(baseLabel,4,0);
    mainLayout->addWidget(baseComboBox,4,1);
}

void Dialog::createContentFrame()
{
    contentFrame = new QFrame ;

    label1 = new QLabel(tr("请选择一个值："));
    label1ComboBox = new QComboBox ;

    label2 = new QLabel(tr("请输入字符串："));
    label2LineEdit = new QLineEdit ;

    textEdit = new QTextEdit ;

    //右上角布局
    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget(label1,0,0);
    topLayout->addWidget(label1ComboBox,0,1);

    topLayout->addWidget(label2,1,0);
    topLayout->addWidget(label2LineEdit,1,1);

    topLayout->addWidget(textEdit,2,0,1,2);



    okButton = new QPushButton(tr("确认")) ;
    cancelButton = new QPushButton(tr("取消"));

    //右下角布局
    QHBoxLayout *buttonLayout = new QHBoxLayout ;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    //整合右边布局
    QVBoxLayout *mainLayout  = new QVBoxLayout(contentFrame);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(buttonLayout);

}
void Dialog::showWindow()
{
    QStringList colorList = QColor::colorNames(); //得到颜色名字并组成列表
    QColor color = QColor(colorList[windowComboBox->currentIndex()]); //获取当前需要的颜色值

    //获取右窗口的调色板信息
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Window , color); //设置背景色
    contentFrame->setPalette(p);
    contentFrame->update() ;

}

//文字颜色的选择
void Dialog::showWindowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = colorList[windowTextComboBox->currentIndex()];

    QPalette p = contentFrame->palette() ;
    p.setColor(QPalette::WindowText,color);
    contentFrame->setPalette(p);
}

//按钮背景色选择
void Dialog::showButton()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonComboBox->currentIndex()]);

    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Button,color);
    contentFrame->setPalette(p);
    contentFrame->update();
}

void Dialog::showButtonText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = colorList[buttonTextComboBox->currentIndex()];

    QPalette p = contentFrame->palette();
    p.setColor(QPalette::ButtonText,color);
    contentFrame->setPalette(p);
}

void Dialog::showBase()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[baseComboBox->currentIndex()]);

    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Base,color);
    contentFrame->setPalette(p);
}

void Dialog::fillColorList(QComboBox *comboBox)
{
    QStringList colorList = QColor::colorNames();

    QColor color ;

    //对颜色名进行遍历
    foreach(color,colorList)
    {
        QPixmap pix(QSize(70,20)); //新图标建一个pix对象作为显示颜色的
        pix.fill(QColor(color)); //用颜色组中的颜色填充图标
        comboBox->addItem(QIcon(pix),NULL);//为下拉选框插入条目
        comboBox->setIconSize(QSize(70,20));//设置条目尺寸
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);//自适应内容大小
    }
}
Dialog::~Dialog()
{

}
