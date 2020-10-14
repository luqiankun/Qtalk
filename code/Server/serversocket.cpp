#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#    pragma execution_character_set("utf-8")
#endif
#include "serversocket.h"

#include <QDateTime>
#include <QElapsedTimer>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
ServerSocket::ServerSocket() {
    sql = new SQL();
    sql->InitSql();
    sql->Open();
    conList = new QList<ClientSocket*>();
    onlineUsers = new QMap<int, QString>();
    listen(QHostAddress::Any, 12345);
}

void ServerSocket::PrintStr(string str) {
    QDateTime time = QDateTime::currentDateTime();
    string nowtime = time.toString().toLocal8Bit().toStdString();
    cout << nowtime + ">>" + QString::fromStdString(str).toLocal8Bit().toStdString() << endl;
}

void ServerSocket::Discon(int t) {
    auto temp = onlineUsers->value(t);
    if (temp == nullptr) {
        for (auto& x : *conList) {
            if (x->des == t) {
                PrintStr(QString::number(x->peerPort()).toStdString() + "|断开与服务器的连接");
                conList->removeOne(x);
            }
        }
    } else {
        sql->Logout(temp);
        onlineUsers->remove(t);
        QJsonDocument doc;
        QJsonArray jsonarray;
        QJsonObject obj;
        QList<QString> users = sql->OnlineList();
        QString temp;

        for (auto& x : users) {
            QJsonArray* temp = new QJsonArray;
            temp->append(x);
            temp->append(sql->HeadOf(x, ""));
            jsonarray.append(*temp);
        }
        obj.insert("header", 5);
        obj.insert("return", 1);
        obj.insert("from", "null");
        obj.insert("msg", jsonarray);
        doc.setObject(obj);
        for (auto& x : *conList) {
            for (auto han : onlineUsers->keys()) {
                if (han == x->socketDescriptor()) {
                    x->write(doc.toJson(QJsonDocument::Compact));
                }
            }
        }
    }
}

void ServerSocket::Login(int handle, QString user, QString pwd) {
    if (sql->Login(user, pwd)) {
        onlineUsers->insert(handle, user);
        // 发送登录成功信号和刷新在线列表给远程端点,并刷新列表
        QString headimg = sql->HeadOf(user, pwd);

        QJsonDocument doc;
        QJsonArray jsonarray;
        QJsonObject obj;
        QList<QString> users = sql->OnlineList();
        for (auto& x : users) {
            QJsonArray* temp = new QJsonArray;
            temp->append(x);
            temp->append(sql->HeadOf(x, ""));
            jsonarray.append(*temp);
        }

        obj.insert("header", 1);
        obj.insert("return", 1);
        obj.insert("from", "null");
        obj.insert("headImg", headimg);

        doc.setObject(obj);
        // qDebug() << str_ << Qt::endl;
        for (auto& x : *conList) {
            if (x->socketDescriptor() == handle) {
                x->write(doc.toJson(QJsonDocument::Compact));
            }
        }
        //发送给所有用户

        obj.insert("header", 5);
        //        obj.value("header") = 5;
        obj.insert("msg", jsonarray);
        doc.setObject(obj);
        for (auto& x : *conList) {
            // TODO
            for (auto han : onlineUsers->keys()) {
                if (han == x->socketDescriptor() && han != handle) {
                    x->write(doc.toJson(QJsonDocument::Compact));
                }
            }
        }

    } else {
        // 发送登录失败信号给远程端点
        QJsonDocument doc;
        QJsonArray jsonarray;
        QJsonObject obj;
        obj.insert("header", 1);
        obj.insert("return", 0);
        obj.insert("from", "null");
        obj.insert("msg", "");
        doc.setObject(obj);
        for (auto& x : *conList) {
            if (x->socketDescriptor() == handle) {
                x->write(doc.toJson(QJsonDocument::Compact));
            }
        }
    }
}

void ServerSocket::Logon(int handle, QString user, QString pwd) {
    if (sql->Logon(user, pwd)) {
        // 发送注册成功信号给远程端点
        QJsonDocument doc;
        QJsonArray jsonarray;
        QJsonObject obj;
        obj.insert("header", 2);
        obj.insert("return", 1);
        obj.insert("from", "null");
        obj.insert("msg", "");
        doc.setObject(obj);

        for (auto& x : *conList) {
            if (x->socketDescriptor() == handle) {
                x->write(doc.toJson(QJsonDocument::Compact));
            }
        }
    } else {
        // 发送注册失败信号给远程端点
        QJsonDocument doc;
        QJsonArray jsonarray;
        QJsonObject obj;
        obj.insert("header", 2);
        obj.insert("return", 0);
        obj.insert("from", "null");
        obj.insert("msg", "");
        doc.setObject(obj);
        for (auto& x : *conList) {
            if (x->socketDescriptor() == handle) {
                x->write(doc.toJson(QJsonDocument::Compact));
            }
        }
    }
}

void ServerSocket::Logout(int handle, QString user) {
    if (sql->Logout(user)) {
        onlineUsers->remove(handle);
        // 发送下线成功信号和刷新在线列表信号给远程端点，并刷新列表
        QJsonDocument doc;
        QJsonArray jsonarray;
        QJsonObject obj;
        QList<QString> users = sql->OnlineList();

        for (auto& x : users) {
            QJsonArray* temp = new QJsonArray;
            temp->append(x);
            temp->append(sql->HeadOf(x, ""));
            jsonarray.append(*temp);
        }
        obj.insert("header", 5);
        obj.insert("return", 1);
        obj.insert("from", "null");
        obj.insert("msg", jsonarray);
        doc.setObject(obj);
        for (auto& x : *conList) {
            for (auto han : onlineUsers->keys()) {
                if (han == x->socketDescriptor()) {
                    x->write(doc.toJson(QJsonDocument::Compact));
                }
            }
        }
    }
}

void ServerSocket::Sendnews(int handle, QString user, QString news) {
    // TODO:发送消息给指定客户端,返回状态给发送者
    if (sql->IsOnline(user) && onlineUsers->value(handle) != nullptr && onlineUsers->key(user) != handle) {
        QJsonDocument doc;
        QJsonObject obj;
        obj.insert("header", 6);
        obj.insert("return", 1);
        obj.insert("from", onlineUsers->value(handle));
        obj.insert("msg", news);

        for (auto& x : *conList) {
            if (x->socketDescriptor() == onlineUsers->key(user)) {
                doc.setObject(obj);
                //                QString str = "61&" + onlineUsers->value(handle) + "&" + news;
                x->write(doc.toJson(QJsonDocument::Compact));
                //        qDebug() << "发送" << str << Qt::endl;
            }
        }

    } else {
        QJsonDocument doc;
        QJsonObject obj;
        obj.insert("header", 3);
        obj.insert("return", 0);
        obj.insert("sendto", user);
        obj.insert("msg", news);
        doc.setObject(obj);
        for (auto& x : *conList) {
            if (x->socketDescriptor() ==handle) {
                x->write(doc.toJson(QJsonDocument::Compact));
            }
        }
    }
}

void ServerSocket::CLoseServer() {
    sql->Close();
    this->close();
}

void ServerSocket::SendUsers(int handle) {
    for (auto& x : onlineUsers->keys()) {
        if (x == handle) {
            QList<QString> users = sql->OnlineList();
            QJsonDocument doc;
            QJsonObject obj;
            QJsonArray jsonarray;
            obj.insert("header", 5);
            obj.insert("return", 1);

            for (auto& x : users) {
                QJsonArray* temp = new QJsonArray;
                temp->append(x);
                temp->append(sql->HeadOf(x, ""));
                jsonarray.append(*temp);
            }
            obj.insert("from", "null");
            obj.insert("msg", jsonarray);
            doc.setObject(obj);
            for (auto& x : *conList) {
                if (x->socketDescriptor() == handle) {
                    x->write(doc.toJson(QJsonDocument::Compact));
                }
            }
        }
    }
}

void ServerSocket::Upheadimg(QString id, QString pwd, QString imgdata) {
    if (sql->Upheadimg(id, pwd, imgdata)) {
        PrintStr(id.toStdString() + " 上传头像成功");
        QJsonDocument doc;
        QJsonObject obj;
        QJsonArray jsonarray;
        obj.insert("header", 7);
        obj.insert("return", 1);
        for (auto var:onlineUsers->values())
        {
            if (var == id) {
                auto v = onlineUsers->key(id);
                for (auto& x : *conList) {
                    if (x->socketDescriptor() == v) {
                        x->write(doc.toJson(QJsonDocument::Compact));
                    }
                }
            }
        }
    } else {
        PrintStr(id.toStdString() + " 上传头像失败");
    }
}

void ServerSocket::incomingConnection(qintptr handle) {
    ClientSocket* tcpclient = new ClientSocket();
    tcpclient->setSocketDescriptor(handle);
    tcpclient->des = handle;
    this->conList->append(tcpclient);
    connect(tcpclient, &ClientSocket::Discon, this, &ServerSocket::Discon);
    connect(tcpclient, &ClientSocket::Login, this, &ServerSocket::Login);
    connect(tcpclient, &ClientSocket::Logon, this, &ServerSocket::Logon);
    connect(tcpclient, &ClientSocket::Logout, this, &ServerSocket::Logout);
    connect(tcpclient, &ClientSocket::Sendnews, this, &ServerSocket::Sendnews);
    connect(tcpclient, &ClientSocket::SendUser, this, &ServerSocket::SendUsers);
    connect(tcpclient, &ClientSocket::Upheadimg, this, &ServerSocket::Upheadimg);
    PrintStr(tcpclient->peerAddress().toString().toStdString() + ":" +
             QString::number(tcpclient->peerPort()).toStdString() + "|连接服务器");
    // TODO：发送连接服务器成功信号给远程端点
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray jsonarray;
    obj.insert("header", 4);
    obj.insert("return", 1);
    obj.insert("from", "null");
    obj.insert("msg", "null");
    doc.setObject(obj);
    tcpclient->write(doc.toJson(QJsonDocument::Compact));
}
