/********************************************************************************
** Form generated from reading UI file 'chatform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATFORM_H
#define UI_CHATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QListWidget *listWidget;
    QTextEdit *SendtextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *sendBtn;

    void setupUi(QWidget *ChatForm)
    {
        if (ChatForm->objectName().isEmpty())
            ChatForm->setObjectName(QString::fromUtf8("ChatForm"));
        ChatForm->resize(500, 522);
        ChatForm->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        verticalLayout_2 = new QVBoxLayout(ChatForm);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(ChatForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("border-radius:7px;"));

        horizontalLayout->addWidget(label_3);

        label = new QLabel(ChatForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(ChatForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2{\n"
"border-radius:5px;\n"
"font: 12pt \"\351\232\266\344\271\246\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"#pushButton_2:hover{\n"
"border-radius:5px;\n"
"font: 12pt \"\351\232\266\344\271\246\";\n"
"color: rgb(255, 255, 255);\n"
"	background-color: rgb(212, 212, 212);\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(ChatForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"border-radius:5px;\n"
"font: 12pt \"\351\232\266\344\271\246\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"#pushButton:hover{\n"
"border-radius:5px;\n"
"font: 12pt \"\351\232\266\344\271\246\";\n"
"color: rgb(255, 255, 255);\n"
"	background-color: rgb(212, 212, 212);\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 9);
        horizontalLayout->setStretch(3, 12);
        horizontalLayout->setStretch(4, 2);
        horizontalLayout->setStretch(5, 2);
        horizontalLayout->setStretch(6, 1);

        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(ChatForm);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 45, 48);"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(listWidget);

        SendtextEdit = new QTextEdit(ChatForm);
        SendtextEdit->setObjectName(QString::fromUtf8("SendtextEdit"));
        SendtextEdit->setStyleSheet(QString::fromUtf8("border:1px solid rgb(56, 49, 45);\n"
"background-color: #252526;\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\256\213\344\275\223\";"));

        verticalLayout->addWidget(SendtextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sendBtn = new QPushButton(ChatForm);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sendBtn->sizePolicy().hasHeightForWidth());
        sendBtn->setSizePolicy(sizePolicy1);
        sendBtn->setMinimumSize(QSize(0, 18));
        sendBtn->setStyleSheet(QString::fromUtf8("#sendBtn{\n"
"\n"
"background-color: rgb(89, 89, 89);\n"
"border-radius:5px;\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\256\213\344\275\223\";\n"
"}\n"
"\n"
"#sendBtn:hover{\n"
"\n"
"background-color: rgb(89, 89, 89);\n"
"border-radius:5px;\n"
"color: rgb(255, 12, 45);\n"
"font: 12pt \"\345\256\213\344\275\223\";\n"
"}"));

        horizontalLayout_2->addWidget(sendBtn);

        horizontalLayout_2->setStretch(0, 3);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);
        verticalLayout->setStretch(2, 4);
        verticalLayout->setStretch(3, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ChatForm);

        QMetaObject::connectSlotsByName(ChatForm);
    } // setupUi

    void retranslateUi(QWidget *ChatForm)
    {
        ChatForm->setWindowTitle(QCoreApplication::translate("ChatForm", "Form", nullptr));
        label_3->setText(QString());
        label->setText(QCoreApplication::translate("ChatForm", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChatForm", "-", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatForm", "X", nullptr));
        sendBtn->setText(QCoreApplication::translate("ChatForm", "\345\217\221  \351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        sendBtn->setShortcut(QCoreApplication::translate("ChatForm", "Ctrl+Return", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class ChatForm: public Ui_ChatForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATFORM_H
