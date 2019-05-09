#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    NationalLabel = new QLabel(tr("国家/地区："));
    NationalComBox = new QComboBox ;
    NationalComBox->addItem("中国");
    NationalComBox->addItem("美国");
    NationalComBox->addItem("英国");

    ProvinceLabel = new QLabel(tr("省份："));
    ProvinceComBox = new QComboBox ;
    ProvinceComBox->addItem("四川省");
    ProvinceComBox->addItem("云南省");
    ProvinceComBox->addItem("贵州省");

    CityLabel = new QLabel(tr("城市："));
    CityLIneEdit = new QLineEdit ;

    IntroductionLabel = new QLabel(tr("个人说明："));
    IntroductionTextEdit = new QTextEdit ;

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    mainLayout->addWidget(NationalLabel,0,0);
    mainLayout->addWidget(NationalComBox,0,1);
    mainLayout->addWidget(ProvinceLabel,1,0);
    mainLayout->addWidget(ProvinceComBox,1,1);
    mainLayout->addWidget(CityLabel,2,0);
    mainLayout->addWidget(CityLIneEdit,2,1);
    mainLayout->addWidget(IntroductionLabel,3,0);
    mainLayout->addWidget(CityLIneEdit,3,1);



}
