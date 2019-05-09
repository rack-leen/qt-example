#include "content.h"
#include <QHBoxLayout>

Content::Content(QWidget *parent)
    : QFrame(parent)
{
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
    baseinfor = new BaseInfor() ; //创建baseinfor对象，将其放入stack框架中
    contact = new Contact() ;
    detail = new Detail() ;

    stack->addWidget(baseinfor);
    stack->addWidget(contact);
    stack->addWidget(detail);

    AmendButton = new QPushButton(tr("修改"));
    CloseButton = new QPushButton(tr("关闭"));
    connect(CloseButton , &QPushButton::clicked , this , &Content::close) ;
    QHBoxLayout *ButtonLayout = new QHBoxLayout;
    ButtonLayout->addStretch(1);
    ButtonLayout->addWidget(AmendButton);
    ButtonLayout->addWidget(CloseButton);

    QVBoxLayout *RightLayout = new QVBoxLayout(this) ;
    RightLayout->setMargin(10);
    RightLayout->setSpacing(6);
    RightLayout->addWidget(stack);
    RightLayout->addLayout(ButtonLayout);

}

Content::~Content()
{

}
