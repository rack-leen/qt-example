/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *love;
    QPushButton *change;
    QToolButton *toolButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton_6;
    QRadioButton *radioButton_3;
    QWidget *page_2;
    QCheckBox *checkBox_4;
    QWidget *page_3;
    QDialogButtonBox *buttonBox_2;
    QWidget *page_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QComboBox *comboBox;
    QFontComboBox *fontComboBox;
    QLineEdit *lineEdit;
    QLabel *labelText;
    QLabel *labelPlain;
    QLabel *labelGif;
    QLabel *labelImage;
    QLabel *labelUrl;
    QLCDNumber *lcdNumber;
    QProgressBar *progressBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(752, 390);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        love = new QPushButton(centralWidget);
        love->setObjectName(QStringLiteral("love"));
        love->setGeometry(QRect(20, 10, 80, 24));
        change = new QPushButton(centralWidget);
        change->setObjectName(QStringLiteral("change"));
        change->setGeometry(QRect(390, 80, 71, 21));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(140, 10, 101, 41));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(510, 220, 201, 101));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 199, 99));
        pushButton2 = new QPushButton(scrollAreaWidgetContents);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(10, 10, 80, 24));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 60, 80, 24));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 10, 80, 24));
        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(110, 60, 80, 24));
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(489, 39, 221, 151));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(90, 50, 80, 24));
        radioButton_3 = new QRadioButton(page);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(70, 90, 99, 22));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        checkBox_4 = new QCheckBox(page_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(60, 80, 84, 22));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        buttonBox_2 = new QDialogButtonBox(page_3);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(30, 100, 166, 24));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        pushButton_7 = new QPushButton(page_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(40, 10, 80, 24));
        pushButton_8 = new QPushButton(page_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(50, 40, 80, 24));
        pushButton_9 = new QPushButton(page_4);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(60, 80, 80, 24));
        stackedWidget->addWidget(page_4);
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 180, 72, 24));
        fontComboBox = new QFontComboBox(centralWidget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(30, 250, 369, 24));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(370, 180, 113, 24));
        labelText = new QLabel(centralWidget);
        labelText->setObjectName(QStringLiteral("labelText"));
        labelText->setGeometry(QRect(180, 70, 58, 16));
        labelPlain = new QLabel(centralWidget);
        labelPlain->setObjectName(QStringLiteral("labelPlain"));
        labelPlain->setGeometry(QRect(180, 100, 58, 16));
        labelGif = new QLabel(centralWidget);
        labelGif->setObjectName(QStringLiteral("labelGif"));
        labelGif->setGeometry(QRect(180, 130, 58, 16));
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(180, 160, 151, 81));
        labelImage->setPixmap(QPixmap(QString::fromUtf8("../../../../../share/Pictures/\346\230\237\351\231\205\350\277\267\350\210\252/1510203372738.jpg")));
        labelUrl = new QLabel(centralWidget);
        labelUrl->setObjectName(QStringLiteral("labelUrl"));
        labelUrl->setGeometry(QRect(350, 115, 131, 41));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(343, 290, 91, 23));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(47, 290, 161, 23));
        progressBar->setValue(24);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 752, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        love->setText(QApplication::translate("MainWindow", "abc", nullptr));
        change->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "cvb", nullptr));
        pushButton2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "RadioButton", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow", "CheckBox", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "123456", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "asdfgrhd", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "\351\230\277\350\276\211", nullptr));

        lineEdit->setText(QApplication::translate("MainWindow", "rack", nullptr));
        labelText->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelPlain->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelGif->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelImage->setText(QString());
        labelUrl->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
