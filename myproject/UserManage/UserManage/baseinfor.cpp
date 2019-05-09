#include "baseinfor.h"

BaseInfor::BaseInfor(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("学生信息管理"); //设置窗口标题
    /************左侧***************/
    UserNameLabel = new QLabel(tr("用户名："));
    UserNameLineEdit = new QLineEdit; //创建行编辑控件

    NameLabel = new QLabel(tr("姓名："));
    NameLineEdit = new QLineEdit; //创建姓名的行编辑控件

    SexLabel = new QLabel("性别：");
    SexComboBox = new QComboBox ; //创建性别的滚动条
    SexComboBox->addItem(tr("男")); //增加内容
    SexComboBox->addItem(tr("女"));

    DepartmentLabel = new QLabel(tr("部门："));
    DepartmentTextEdit = new QTextEdit ; //创建部门的文本编辑控件

    AgeLabel = new QLabel(tr("年龄："));
    AgeLineEdit = new QLineEdit ; //创建年龄的行编辑控件

    OtherLabel = new QLabel(tr("备注："));
//    OtherTextEdit = new QTextEdit;
    OtherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    //将创建的控件增加到布局中

    //将左边的控件增加到左边网格布局中
    LeftLayout = new QGridLayout() ; //创建网格布局
    LeftLayout->addWidget(UserNameLabel , 0,0); //增加用户名控件到第一个的第一列
    LeftLayout->addWidget(UserNameLineEdit,0,1);

    LeftLayout->addWidget(NameLabel,1,0);
    LeftLayout->addWidget(NameLineEdit,1,1);

    LeftLayout->addWidget(SexComboBox,2,0);
    LeftLayout->addWidget(SexComboBox,2,0);

    LeftLayout->addWidget(DepartmentLabel , 3,0);
    LeftLayout->addWidget(DepartmentTextEdit,3,1);

    LeftLayout->addWidget(AgeLabel ,4,0);
    LeftLayout->addWidget(AgeLineEdit,4,1);

    LeftLayout->addWidget(OtherLabel,5,0,1,2);

    LeftLayout->setColumnStretch(0,1); //第0列拉伸为1
    LeftLayout->setColumnStretch(1,3); //第1列拉伸为3

    /**************右侧*****************/
    HeadLabel = new QLabel(tr("头像"));
    HeadIconLabel = new QLabel ;
    QPixmap icon("");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(),icon.height()); //设置图标高宽
    HeadUpdate = new QPushButton(tr("更新"));

    TopRightLayout = new QHBoxLayout() ;
    TopRightLayout->setSpacing(20); //设置间隙
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLabel);
    TopRightLayout->addWidget(HeadUpdate);

    /**************右下角***********************/
    IntroductionLabel = new QLabel(tr("个人说明："));
    IntroductionEdit = new QTextEdit ;

    RightLayout = new QVBoxLayout() ;
    RightLayout->setMargin(20);
    RightLayout->addLayout(TopRightLayout); //将右上角布局加入右下角布局
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionEdit);

    /***************底部***************************/
    OkButton = new QPushButton(tr("确认"));
    CancelButton = new QPushButton(tr("取消"));

    ButtonLayout = new QHBoxLayout() ;
    ButtonLayout->addStretch();
    ButtonLayout->addWidget(OkButton);
    ButtonLayout->addWidget(CancelButton);

    /****************主窗口布局*************************************/
    QGridLayout *mainLayout = new QGridLayout(this) ;
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(LeftLayout,0,0);
    mainLayout->addLayout(RightLayout,0,1);
    mainLayout->addLayout(ButtonLayout,1,0,1,2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
