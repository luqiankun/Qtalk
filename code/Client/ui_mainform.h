/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *minBtn;
    QPushButton *closeAllBtn;
    QHBoxLayout *horizontalLayout;
    QLabel *headLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *nichengLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QListWidget *usersList;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(279, 600);
        MainForm->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 80);"));
        verticalLayout_2 = new QVBoxLayout(MainForm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(MainForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/img/logo.png);"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        minBtn = new QPushButton(MainForm);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minBtn->sizePolicy().hasHeightForWidth());
        minBtn->setSizePolicy(sizePolicy);
        minBtn->setMaximumSize(QSize(30, 16777215));
        minBtn->setStyleSheet(QString::fromUtf8("#minBtn{\n"
"border-image: url(:/img/3.png);\n"
"border-radius:5px;\n"
"}\n"
"#minBtn:hover{\n"
"	background-color: rgb(163, 100, 71);\n"
"border-image: url(:/img/3.png);\n"
"border-radius:5px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(minBtn);

        closeAllBtn = new QPushButton(MainForm);
        closeAllBtn->setObjectName(QString::fromUtf8("closeAllBtn"));
        sizePolicy.setHeightForWidth(closeAllBtn->sizePolicy().hasHeightForWidth());
        closeAllBtn->setSizePolicy(sizePolicy);
        closeAllBtn->setMaximumSize(QSize(30, 16777215));
        closeAllBtn->setStyleSheet(QString::fromUtf8("#closeAllBtn{\n"
"border-image: url(:/img/4.png);\n"
"border-radius:5px;\n"
"}\n"
"#closeAllBtn:hover{\n"
"	background-color: rgb(163, 100, 71);\n"
"border-image: url(:/img/4.png);\n"
"border-radius:5px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(closeAllBtn);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 9);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        headLabel = new QLabel(MainForm);
        headLabel->setObjectName(QString::fromUtf8("headLabel"));
        headLabel->setMinimumSize(QSize(0, 58));
        headLabel->setMouseTracking(true);
        headLabel->setFocusPolicy(Qt::ClickFocus);
        headLabel->setStyleSheet(QString::fromUtf8("\n"
"border-radius:13px;"));

        horizontalLayout->addWidget(headLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nichengLabel = new QLabel(MainForm);
        nichengLabel->setObjectName(QString::fromUtf8("nichengLabel"));
        nichengLabel->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\215\216\345\205\211\350\203\226\345\244\264\351\261\274_CNKI\";"));

        horizontalLayout->addWidget(nichengLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(MainForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setStyleSheet(QString::fromUtf8("border-bottom:1px solid ;\n"
"background-color: rgb(52, 173, 229);\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"padding-left:10px;\n"
"border-radius:5px;"));

        verticalLayout->addWidget(label_2);

        usersList = new QListWidget(MainForm);
        usersList->setObjectName(QString::fromUtf8("usersList"));
        usersList->setFocusPolicy(Qt::NoFocus);
        usersList->setStyleSheet(QString::fromUtf8("\n"
"#uersList{\n"
"color:rgb(173,175,178);background:rgb(125,127,131);;border:0px solid gray;\n"
"	\n"
"}\n"
"#usersList::Item{\n"
" background: transparent;\n"
"height:60px;padding-left:5px;\n"
"	font: 28pt \"\351\232\266\344\271\246\";\n"
"}\n"
"#usersList::Item:hover{\n"
"color:rgb(255,55,255);background:transparent;border-left:7px solid rgb(255,0,0);\n"
"}\n"
""));
        usersList->setFrameShape(QFrame::NoFrame);
        usersList->setSelectionMode(QAbstractItemView::SingleSelection);
        usersList->setIconSize(QSize(60, 60));

        verticalLayout->addWidget(usersList);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(3, 16);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "Form", nullptr));
        label->setText(QString());
        minBtn->setText(QString());
        closeAllBtn->setText(QString());
        headLabel->setText(QString());
        nichengLabel->setText(QCoreApplication::translate("MainForm", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainForm", "\345\234\250\347\272\277\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
