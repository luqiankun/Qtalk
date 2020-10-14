/********************************************************************************
** Form generated from reading UI file 'tishi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TISHI_H
#define UI_TISHI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tishi
{
public:
    QLabel *label;
    QPushButton *okBtn;
    QPushButton *noBtn;

    void setupUi(QWidget *Tishi)
    {
        if (Tishi->objectName().isEmpty())
            Tishi->setObjectName(QString::fromUtf8("Tishi"));
        Tishi->resize(294, 105);
        Tishi->setStyleSheet(QString::fromUtf8("background-color: rgb(97, 97, 97);"));
        label = new QLabel(Tishi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 241, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 76, 32);\n"
""));
        okBtn = new QPushButton(Tishi);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(30, 80, 75, 23));
        okBtn->setStyleSheet(QString::fromUtf8("#okBtn{\n"
"color: rgb(255, 255, 255);\n"
"	background-color: rgb(74, 74, 74);\n"
"border-radius:5px;\n"
"}\n"
""));
        noBtn = new QPushButton(Tishi);
        noBtn->setObjectName(QString::fromUtf8("noBtn"));
        noBtn->setGeometry(QRect(190, 80, 75, 23));
        noBtn->setStyleSheet(QString::fromUtf8("#noBtn{\n"
"color: rgb(255, 255, 255);\n"
"	background-color: rgb(74, 74, 74);\n"
"border-radius:5px;\n"
"}\n"
""));

        retranslateUi(Tishi);

        QMetaObject::connectSlotsByName(Tishi);
    } // setupUi

    void retranslateUi(QWidget *Tishi)
    {
        Tishi->setWindowTitle(QCoreApplication::translate("Tishi", "Form", nullptr));
        label->setText(QCoreApplication::translate("Tishi", "\346\224\266\345\210\260\346\235\245\350\207\252l\347\232\204\346\266\210\346\201\257", nullptr));
        okBtn->setText(QCoreApplication::translate("Tishi", "\346\237\245\347\234\213", nullptr));
        noBtn->setText(QCoreApplication::translate("Tishi", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tishi: public Ui_Tishi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TISHI_H
