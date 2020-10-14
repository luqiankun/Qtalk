#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#    pragma execution_character_set("utf-8")
#endif
#include "chatform.h"

#include <QBitmap>
#include <QDateTime>
#include <QDebug>
#include <QMouseEvent>
#include <QMovie>
#include <QPainter>
#include <iostream>

#include "ui_chatform.h"

void ChatForm::dealMessage(QNChatMessage* messageW, QListWidgetItem* item, QString text, QString time,
                           QNChatMessage::User_Type type) {
    messageW->setFixedWidth(this->width());
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);
    messageW->setText(text, time, size, type);
    ui->listWidget->setItemWidget(item, messageW);
}

void ChatForm::dealMessageTime(QString curMsgTime) {
    bool isShowTime = false;
    if (ui->listWidget->count() > 0) {
        QListWidgetItem* lastItem = ui->listWidget->item(ui->listWidget->count() - 1);
        QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        isShowTime = ((curTime - lastTime) > 60);  // 两个消息相差一分钟
                                                   //        isShowTime = true;
    } else {
        isShowTime = true;
    }
    if (isShowTime) {
        QNChatMessage* messageTime = new QNChatMessage(ui->listWidget->parentWidget());
        QListWidgetItem* itemTime = new QListWidgetItem(ui->listWidget);

        QSize size = QSize(this->width(), 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size, QNChatMessage::User_Time);
        ui->listWidget->setItemWidget(itemTime, messageTime);
    }
}



void ChatForm::MessageOfMe(QString msg) {
    dealMessageTime(QString::number(QDateTime::currentDateTime().toTime_t()));

    QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    dealMessage(messageW, item, msg, QString::number(QDateTime::currentDateTime().toTime_t()), QNChatMessage::User_Me);
    ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
    //  messageW->setTextSuccess();
}

void ChatForm::MessgaeOfShe(QString msg) {
    dealMessageTime(QString::number(QDateTime::currentDateTime().toTime_t()));

    QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    dealMessage(messageW, item, msg, QString::number(QDateTime::currentDateTime().toTime_t()), QNChatMessage::User_She);
    ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
    //  messageW->setTextSuccess();
}

void ChatForm::Sendstatue(bool p) {
    if (!p) {
        MessageOfMe("系统提示：发送失败");
    }
}

void ChatForm::Rece(QString msg) { this->MessgaeOfShe(msg); }

ChatForm::ChatForm(QString s) : ui(new Ui::ChatForm) {
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->Widget_ID = s;
    ui->label->setText("正在和" + this->Widget_ID + "对话...");
    mouve = new QMovie(this);
    mouve->setFileName(":/img/3.gif");

    mouve->setScaledSize(QSize(32, 32));
    mouve->start();
    ui->label_3->resize(32, 32);
    ui->label_3->setMovie(mouve);
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QBitmap bmp(this->size());

    bmp.fill();

    QPainter p(&bmp);

    p.setPen(Qt::NoPen);

    p.setBrush(Qt::black);

    p.drawRoundedRect(bmp.rect(), 17, 17);
    setMask(bmp);
}

ChatForm::~ChatForm() { delete ui; }

void ChatForm::on_sendBtn_clicked() {
    if (ui->SendtextEdit->toPlainText() != "") {
        emit Send( this->Widget_ID, ui->SendtextEdit->toPlainText());
        this->MessageOfMe(ui->SendtextEdit->toPlainText());
        ui->SendtextEdit->clear();
    }
}

void ChatForm::on_pushButton_clicked() { emit Close(this->Widget_ID); }

void ChatForm::mouseMoveEvent(QMouseEvent* event) {
    if (this->IsPress)
        this->move(event->globalPos() - this->mouse);
}

void ChatForm::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        this->IsPress = true;
        this->mouse = event->globalPos() - this->pos();
    }
}

void ChatForm::mouseReleaseEvent(QMouseEvent*) {
    this->mouse = QPoint();
    this->IsPress = false;
}

void ChatForm::on_pushButton_2_clicked() { this->hide(); }
