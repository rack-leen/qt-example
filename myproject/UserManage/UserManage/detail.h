#ifndef DETAIL_H
#define DETAIL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QComboBox>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *NationalLabel ; //国家
    QComboBox *NationalComBox ;
    QLabel *ProvinceLabel ; //省
    QComboBox *ProvinceComBox ;
    QLabel *CityLabel ;
    QLineEdit *CityLIneEdit ;
    QLabel *IntroductionLabel ;
    QTextEdit *IntroductionTextEdit;
    QGridLayout *mainLayout ;
};

#endif // DETAIL_H
