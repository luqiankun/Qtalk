/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *loginBtn;
    QPushButton *userBtn;
    QLabel *statusLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *userLineedit;
    QLineEdit *pwdLineedit;
    QLabel *label;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLineEdit *IPlineedit;
    QLineEdit *Portlineedit;
    QLabel *IPlabel;
    QLabel *Portlabel;
    QPushButton *setokBtn;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *logonBtn;
    QPushButton *setBtn;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 521);
        Form->setStyleSheet(QString::fromUtf8("#Form{\n"
"	background-color: rgb(121, 121, 121);\n"
"\n"
"}"));
        loginBtn = new QPushButton(Form);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(160, 200, 141, 41));
        loginBtn->setStyleSheet(QString::fromUtf8("#loginBtn{\n"
"border-radius:8px;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(40, 168, 234);\n"
"}\n"
"#loginBtn:hover{\n"
"border-radius:8px;\n"
"	color: rgb(255, 0, 255);\n"
"	background-color: rgb(40, 168, 234);\n"
"}"));
        userBtn = new QPushButton(Form);
        userBtn->setObjectName(QString::fromUtf8("userBtn"));
        userBtn->setGeometry(QRect(90, 184, 71, 71));
        userBtn->setStyleSheet(QString::fromUtf8(""));
        statusLabel = new QLabel(Form);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(180, 250, 141, 31));
        statusLabel->setStyleSheet(QString::fromUtf8("color: rgb(213, 81, 28);"));
        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 50, 209, 139));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        userLineedit = new QLineEdit(widget);
        userLineedit->setObjectName(QString::fromUtf8("userLineedit"));
        userLineedit->setMinimumSize(QSize(0, 30));
        userLineedit->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 188, 188);\n"
"border-radius:10px;"));
        userLineedit->setFrame(false);

        verticalLayout->addWidget(userLineedit);

        pwdLineedit = new QLineEdit(widget);
        pwdLineedit->setObjectName(QString::fromUtf8("pwdLineedit"));
        pwdLineedit->setMinimumSize(QSize(0, 30));
        pwdLineedit->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 188, 188);border-radius:10px;"));
        pwdLineedit->setFrame(false);
        pwdLineedit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(pwdLineedit);

        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 240, 54, 21));
        label->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 238);\n"
"font: 8pt \".PingFang SC\";"));
        widget1 = new QWidget(Form);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(30, 360, 341, 121));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        IPlineedit = new QLineEdit(widget1);
        IPlineedit->setObjectName(QString::fromUtf8("IPlineedit"));

        gridLayout->addWidget(IPlineedit, 0, 1, 1, 1);

        Portlineedit = new QLineEdit(widget1);
        Portlineedit->setObjectName(QString::fromUtf8("Portlineedit"));

        gridLayout->addWidget(Portlineedit, 1, 1, 1, 1);

        IPlabel = new QLabel(widget1);
        IPlabel->setObjectName(QString::fromUtf8("IPlabel"));

        gridLayout->addWidget(IPlabel, 0, 0, 1, 1);

        Portlabel = new QLabel(widget1);
        Portlabel->setObjectName(QString::fromUtf8("Portlabel"));

        gridLayout->addWidget(Portlabel, 1, 0, 1, 1);

        setokBtn = new QPushButton(widget1);
        setokBtn->setObjectName(QString::fromUtf8("setokBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(setokBtn->sizePolicy().hasHeightForWidth());
        setokBtn->setSizePolicy(sizePolicy);
        setokBtn->setMaximumSize(QSize(16777215, 40));
        setokBtn->setStyleSheet(QString::fromUtf8("border-radius:6px;\n"
"background-color: rgb(157, 136, 131);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(setokBtn, 2, 0, 1, 1);

        widget2 = new QWidget(Form);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(270, 0, 121, 31));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        logonBtn = new QPushButton(widget2);
        logonBtn->setObjectName(QString::fromUtf8("logonBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logonBtn->sizePolicy().hasHeightForWidth());
        logonBtn->setSizePolicy(sizePolicy1);
        logonBtn->setStyleSheet(QString::fromUtf8("\n"
"\n"
"#logonBtn{\n"
"border-radius:5px;\n"
"border-image: url(:/img/5.png);}\n"
"#logonBtn:hover{\n"
"border-radius:5px;\n"
"border-image: url(:/img/5.png);\n"
"	background-color: rgb(172, 255, 175);\n"
"}"));

        horizontalLayout->addWidget(logonBtn);

        setBtn = new QPushButton(widget2);
        setBtn->setObjectName(QString::fromUtf8("setBtn"));
        sizePolicy1.setHeightForWidth(setBtn->sizePolicy().hasHeightForWidth());
        setBtn->setSizePolicy(sizePolicy1);
        setBtn->setToolTipDuration(-1);
        setBtn->setStyleSheet(QString::fromUtf8("\n"
"#setBtn{\n"
"border-radius:5px;\n"
"border-image: url(:/img/set.png);}\n"
"#setBtn:hover{\n"
"border-radius:5px;\n"
"border-image: url(:/img/set.png);\n"
"	background-color: rgb(172, 255, 175);\n"
"}"));

        horizontalLayout->addWidget(setBtn);

        pushButton_4 = new QPushButton(widget2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setStyleSheet(QString::fromUtf8("#pushButton_4{\n"
"border-radius:5px;\n"
"border-image: url(:/img/3.png);}\n"
"#pushButton_4:hover{border-radius:5px;\n"
"border-image: url(:/img/3.png);\n"
"	background-color: rgb(172, 255, 175);\n"
"}"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(widget2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setToolTipDuration(-1);
        pushButton_6->setStyleSheet(QString::fromUtf8("#pushButton_6{border-radius:5px;\n"
"border-image: url(:/img/4.png);}\n"
"#pushButton_6:hover{border-radius:5px;\n"
"border-image: url(:/img/4.png);\n"
"	background-color: rgb(172, 255, 175);\n"
"}"));

        horizontalLayout->addWidget(pushButton_6);

        QWidget::setTabOrder(userLineedit, pwdLineedit);
        QWidget::setTabOrder(pwdLineedit, loginBtn);
        QWidget::setTabOrder(loginBtn, userBtn);
        QWidget::setTabOrder(userBtn, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_6);
        QWidget::setTabOrder(pushButton_6, setBtn);
        QWidget::setTabOrder(setBtn, logonBtn);
        QWidget::setTabOrder(logonBtn, IPlineedit);
        QWidget::setTabOrder(IPlineedit, Portlineedit);
        QWidget::setTabOrder(Portlineedit, setokBtn);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        loginBtn->setText(QCoreApplication::translate("Form", "\347\231\273\345\275\225", nullptr));
        userBtn->setText(QString());
        statusLabel->setText(QString());
        userLineedit->setPlaceholderText(QCoreApplication::translate("Form", "\350\276\223\345\205\245\344\275\240\347\232\204\350\264\246\345\217\267", nullptr));
        pwdLineedit->setPlaceholderText(QCoreApplication::translate("Form", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("Form", "\350\256\260\344\275\217\350\264\246\345\217\267", nullptr));
        IPlineedit->setText(QCoreApplication::translate("Form", "127.0.0.1", nullptr));
        IPlineedit->setPlaceholderText(QCoreApplication::translate("Form", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", nullptr));
        Portlineedit->setText(QCoreApplication::translate("Form", "1234", nullptr));
        Portlineedit->setPlaceholderText(QCoreApplication::translate("Form", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267", nullptr));
        IPlabel->setText(QCoreApplication::translate("Form", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        Portlabel->setText(QCoreApplication::translate("Form", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        setokBtn->setText(QCoreApplication::translate("Form", "\347\241\256\345\256\232", nullptr));
#if QT_CONFIG(tooltip)
        logonBtn->setToolTip(QCoreApplication::translate("Form", "\350\276\223\345\205\245\346\203\263\350\246\201\346\263\250\345\206\214\347\232\204\350\264\246\345\217\267\345\222\214\345\257\206\347\240\201\357\274\214\347\204\266\345\220\216\347\202\271\345\207\273\346\255\244\346\214\211\351\222\256\346\263\250\345\206\214", nullptr));
#endif // QT_CONFIG(tooltip)
        logonBtn->setText(QString());
#if QT_CONFIG(tooltip)
        setBtn->setToolTip(QCoreApplication::translate("Form", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        setBtn->setText(QString());
        pushButton_4->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("Form", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_6->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
