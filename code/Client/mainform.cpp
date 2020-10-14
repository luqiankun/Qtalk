#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#    pragma execution_character_set("utf-8")
#endif
#include "mainform.h"

#include <tishi.h>

#include <QBitmap>
#include <QBuffer>
#include <QDebug>
#include <QDragEnterEvent>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMessageBox>
#include <QMimeData>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QRandomGenerator>
#include <QTime>
#include <QTimer>
#include <QUrl>
#include <QtEvents>
#include <iostream>
#include <QSystemtrayIcon>
#include "ui_mainform.h"
MainForm::MainForm(QWidget* parent) : QWidget(parent), ui(new Ui::MainForm) {
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->client = new QTcpSocket(this);
    this->login = new Login();
    this->setWindowIcon(QIcon(":/img/logo.png"));
    connect(login, &Login::LoginUser, this, &MainForm::LoginUser);
    connect(login, &Login::LogonUser, this, &MainForm::LogonUser);
    connect(login, &Login::ShowMainForm, this, &MainForm::ShowMainForm);
    connect(login, &Login::ServerSet, this, &MainForm::Serverset);
    connect(login, &Login::CloseAll, this, [=] { QApplication::exit(); });
    connect(this, &MainForm::IsConSer, login, &Login::IsConser);
    connect(this, &MainForm::Login_, login, &Login::Login_);
    connect(this, &MainForm::Logon_, login, &Login::Logon_);

    login->show();
    login->First();
    //圆角
    QBitmap bmp(this->size());

    bmp.fill();

    QPainter p(&bmp);

    p.setPen(Qt::NoPen);

    p.setBrush(Qt::black);

    p.drawRoundedRect(bmp.rect(), 17, 17);

    setMask(bmp);
    //托盘

    tuoPan = new QSystemTrayIcon();
    tuoPan->setIcon(QIcon(":/img/logo.png"));
    connect(tuoPan, &QSystemTrayIcon::activated, [&](QSystemTrayIcon::ActivationReason p) {
        if (p == QSystemTrayIcon::ActivationReason::DoubleClick && this->isHidden()) {
            this->show();
        }
        if (p == QSystemTrayIcon::ActivationReason::Trigger) {
            tuoPan->setIcon(QIcon(":img/logo.png"));
        }
        if (p == QSystemTrayIcon::ActivationReason::MiddleClick) {
            tuoPan->hide();
            qApp->exit(0);
        }
    });
    menubar = new QMenu(this);
    closeAct = new QAction("关闭", this);
    closeAct->setIcon(QIcon(":/img/4.png"));
    showmainForm = new QAction("显示", this);
    showmainForm->setIcon(QIcon(":/img/6.png"));
    menubar->addAction(showmainForm);
    menubar->addAction(closeAct);

    tuoPan->setContextMenu(menubar);
    tuoPan->setToolTip(this->userName);
    connect(closeAct, &QAction::triggered, this, [&] { tuoPan->hide(), qApp->exit(0); });
    connect(showmainForm, &QAction::triggered, this, [this] { this->show(); });
    //    ui->headLabel->installEventFilter(ui->headLabel);

    //
}

MainForm::~MainForm() { delete ui; }

void MainForm::ShowMainForm() {
    tuoPan->show();
    this->show();
    this->ui->nichengLabel->setText(userName);
    QJsonDocument doc;
    QJsonObject json;
    json.insert("header", 4);
    json.insert("id", userName);
    json.insert("pwd", pwd);
    doc.setObject(json);
    client->write(doc.toJson(QJsonDocument::Compact), doc.toJson(QJsonDocument::Compact).length());
}

void MainForm::LoginUser(QString name, QString pwd) {
    this->userName = name;
    this->pwd = pwd;
    QJsonDocument doc;
    QJsonObject json;
    json.insert("header", 1);
    json.insert("id", name);
    json.insert("pwd", pwd);
    doc.setObject(json);
    client->write(doc.toJson(QJsonDocument::Compact));
}

void MainForm::LogonUser(QString name, QString pwd) {
    QJsonDocument doc;
    QJsonObject json;
    json.insert("header", 2);
    json.insert("id", name);
    json.insert("pwd", pwd);
    doc.setObject(json);
    client->write(doc.toJson(QJsonDocument::Compact), doc.toJson(QJsonDocument::Compact).length());
}

void MainForm::Serverset(QString ip, int port) {
    if (client->isOpen()) {
        emit this->IsConSer(true);
        return;
    }
    emit this->IsConSer(false);
    client->connectToHost(ip, port);

    connect(client, &QTcpSocket::connected, this, [&] {
        emit this->IsConSer(true);
        connect(client, &QTcpSocket::readyRead, this, &MainForm::ProcessNews);
        connect(client, &QTcpSocket::disconnected, this, [&] {
            tuoPan->hide();
            //            emit this->IsConSer(false);
            QMessageBox::StandardButton res =
                QMessageBox::information(NULL, "正在关闭软件....", "已和服务器断开,点击ok关闭软件");
            if (res == QMessageBox::Ok) {
                QApplication::exit(0);
            }
        });
    });
}

void MainForm::ProcessNews() {
    while (client->bytesAvailable() > 0) {
        QByteArray data;
        data = client->readAll();
        QJsonDocument doc;
        doc = QJsonDocument::fromJson(data);
        //        qDebug() << doc;
        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            QJsonValue value = obj.value("header");
            if (value.toInt() == 1) {  //上线
                if (obj.value("return").toInt() == 0) {
                    emit Login_(false);
                } else if (obj.value("return").toInt() == 1) {
                    emit Login_(true);
                    if (obj.value("headImg") == "") {
                        QPixmap p = QPixmap(":/img/7.png");
                        ui->headLabel->setPixmap(p.scaled(ui->headLabel->size()));
                    } else {
                        QPixmap p = pixmapFrom(obj.value("headImg"));
                        ui->headLabel->setPixmap(p.scaled(ui->headLabel->size()));
                    }
                }
            }
            if (value.toInt() == 2) {  //注册
                if (obj.value("return").toInt() == 0) {
                    emit Logon_(false);
                } else if (obj.value("return").toInt() == 1) {
                    emit Logon_(true);
                }
            }
            if (value.toInt() == 3) {  //发送消息
                if (obj.value("return").toInt() == 0) {
                    for (auto& x : ChatWidgets) {
                        if (x->Widget_ID == obj.value("sendto").toString()) {
                            x->Sendstatue(false);
                        }
                    }
                }
            }
            if (value.toInt() == 4) {  //连接服务器
                if (obj.value("return").toInt() == 1) {
                    emit IsConSer(true);
                }
            }
            if (value.toInt() == 5) {  //刷新在线列表
                ui->usersList->clear();
                if (obj.value("return").toInt() == 1) {
                    QJsonArray jsonarray;
                    jsonarray = obj.value("msg").toArray();
                    for (QJsonArray::iterator it = jsonarray.begin(); it != jsonarray.end(); ++it) {
                        QListWidgetItem* add_item = new QListWidgetItem();
                        if (it->toArray().at(0).toString() != this->userName) {
                            add_item->setText(it->toArray().at(0).toString());
                            if (it->toArray().at(1).toString() == "") {
                                QRandomGenerator* rand = new QRandomGenerator;
                                rand->seed(QTime::currentTime().msecsSinceStartOfDay());
                                int num = rand->bounded(22, 81);
                                QString path = ":/img/picture-13" + QString::number(num) + ".jpg";
                                add_item->setIcon(QIcon(path));
                            } else {
                                QPixmap p = pixmapFrom(it->toArray().at(1).toString());
                                add_item->setIcon(QIcon(p));
                            }
                            ui->usersList->addItem(add_item);
                        }
                    }
                }
            }
            if (value.toInt() == 6) {  //收到消息
                if (obj.value("return").toInt() == 1) {
                    bool temp = false;
                    for (auto x : ChatWidgets) {
                        if (x->Widget_ID == obj.value("from").toString()) {
                            temp = true;
                        }
                        x->Rece(obj.value("msg").toString());
                        //                        qDebug() << "news:" << obj.value("msg").toString() << Qt::endl;
                        if (!x->isVisible()) {
                            delete tishi;
                            tishi = new Tishi(obj.value("from").toString());
                            connect(tishi, &Tishi::See, this, [=](QString) { x->show(); });
                        }
                    }
                    if (temp) {
                        return;
                    } else {
                        ChatForm* temp = new ChatForm(obj.value("from").toString());

                        connect(temp, &ChatForm::Close, this, &MainForm::CloseChatWidget);
                        connect(temp, &ChatForm::Send, this, &MainForm::SendToSomeone);
                        ChatWidgets.append(temp);
                        //                        delete tishi;
                        tishi = new Tishi(obj.value("from").toString());
                        connect(tishi, &Tishi::See, this, [=](QString) { temp->show(); });
                    }
                    for (auto& x : ChatWidgets) {
                        if (x->Widget_ID == obj.value("from").toString()) {
                            x->Rece(obj.value("msg").toString());
                            if (!x->isVisible()) {
                                delete tishi;
                                tishi = new Tishi(obj.value("from").toString());
                                connect(tishi, &Tishi::See, this, [=](QString) { x->show(); });
                            }
                            return;
                        }
                    }
                }
                if (value.toInt() == 7) {
                    if (obj.value("return").toInt() == 1) {
                    
                    }

                }
            }
        }
    }
}

void MainForm::CloseChatWidget(QString str) {
    for (auto& x : ChatWidgets) {
        if (x->Widget_ID == str) {
            ChatWidgets.removeOne(x);
            x->close();
            return;
        }
    }
}

void MainForm::SendToSomeone(QString Name, QString str_) {
    QJsonDocument doc;
    QJsonObject json;
    json.insert("header", 3);
    json.insert("sendto", Name);
    json.insert("msg", str_);
    doc.setObject(json);
    client->write(doc.toJson(QJsonDocument::Compact));
}

void MainForm::mouseMoveEvent(QMouseEvent* event) {
    if (this->IsPress)
        this->move(event->globalPos() - this->mouse);
}

void MainForm::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && event->y() < 50) {
        this->IsPress = true;
        this->mouse = event->globalPos() - this->pos();
    }
}

void MainForm::mouseReleaseEvent(QMouseEvent*) {
    this->mouse = QPoint();
    this->IsPress = false;
}

void MainForm::mouseDoubleClickEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && event->y() < 100 && event->y() > 50 && event->x() < 60) {
        QString path = QFileDialog::getOpenFileName(this, "请选择图片", "/", "图片文件 (*.png *.jpg *.jpeg *.bmp);;");
        if (!path.isEmpty()) {
            QFile file(path);
            QFileInfo info(path);
            QString suffix = info.suffix();

            file.open(QIODevice::ReadOnly);
            QByteArray data;
            data = file.readAll();
            QPixmap img;
            if (suffix=="png")
            {
                img.loadFromData(data, "png");
            }
            if (suffix == "jpg")
            {
                img.loadFromData(data, "jpg");
            }
            if (suffix == "jpeg")
            {
                img.loadFromData(data, "jpeg");
            }
            if (suffix == "bmp")
            {
                img.loadFromData(data, "bmp");
            }
            img = img.scaled(ui->headLabel->size());
            ui->headLabel->setPixmap(img);
            file.close();
            //            QJsonValue;
            //            QVariant var(data);
            QJsonDocument doc;
            QJsonObject json;
            json.insert("header", 5);
            json.insert("id", userName);
            json.insert("pwd", pwd);
            json.insert("msg", jsonValFromPixmap(img));
            //            qDebug() << data;

            doc.setObject(json);
            client->write(doc.toJson(QJsonDocument::Compact), doc.toJson(QJsonDocument::Compact).length());
        }
    }
}
QPixmap MainForm::pixmapFrom(const QJsonValue& val) {
    auto const encoded = val.toString().toLocal8Bit();
    QPixmap p;
    p.loadFromData(QByteArray::fromBase64(encoded), "PNG");
    return p;
}
QJsonValue MainForm::jsonValFromPixmap(const QPixmap& p) {
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    p.save(&buffer, "PNG");
    auto const encoded = buffer.data().toBase64();
    return {QString::fromLocal8Bit(encoded)};
}
void MainForm::on_usersList_itemDoubleClicked(QListWidgetItem* item) {
    std::cout << "item ulji";
    for (auto& x : ChatWidgets) {
        if (x->Widget_ID == item->text()) {
            x->show();
            return;
        }
    }
    ChatForm* temp = new ChatForm(item->text());

    connect(temp, &ChatForm::Close, this, &MainForm::CloseChatWidget);
    connect(temp, &ChatForm::Send, this, &MainForm::SendToSomeone);
    ChatWidgets.append(temp);
    temp->show();
}

void MainForm::on_closeAllBtn_clicked() { this->hide(); }

void MainForm::on_minBtn_clicked() { setWindowState(Qt::WindowState::WindowMinimized); }
