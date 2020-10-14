#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#    pragma execution_character_set("utf-8")
#endif
#include "clientsocket.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <iostream>
ClientSocket::ClientSocket() {
    des = NULL;
    connect(this, &ClientSocket::readyRead, this, &ClientSocket::DataRece);
    connect(this, &ClientSocket::disconnected, this, &ClientSocket::DiscCon);
}
/**
 * @brief 接收到Json格式的消息后处理函数
 * 
 */
void ClientSocket::DataRece() {
    while (bytesAvailable() > 0) {
        int len = bytesAvailable();
        QByteArray data;
        data.resize(len);
        read(data.data(), data.size());
        //        QString msg = QString::fromLocal8Bit(data.data());
        //    std::cout << msg.toStdString() << std::endl;
        QJsonDocument doc;
        //        qDebug() << data;
        doc = QJsonDocument::fromJson(data);
        //        qDebug() << doc.toJson(QJsonDocument::JsonFormat::Compact);
        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            QJsonValue value = obj.value("header");
            if (value.toInt() == 0) {  //下线
                emit Logout(des, obj.value("id").toString());
            }
            if (value.toInt() == 1) {  //上线
                                       //                qDebug() << "1";
                emit this->Login(des, obj.value("id").toString(), obj.value("pwd").toString());
            }
            if (value.toInt() == 2) {  //注册
                emit this->Logon(des, obj.value("id").toString(), obj.value("pwd").toString());
            }
            if (value.toInt() == 3) {  //发送消息
                emit Sendnews(des, obj.value("sendto").toString(), obj.value("msg").toString());
                qDebug() << des << "发送给" << obj.value("sendto").toString() <<"消息：" << obj.value("msg").toString()
                    << Qt::endl;
            }
            if (value.toInt() == 4) {  //请求在线列表
                emit SendUser(des);
            }
            if (value.toInt() == 5) {  //上传头像
                QJsonObject obj = doc.object();
                QJsonValue value = obj.value("msg");
                emit Upheadimg(obj.value("id").toString(), obj.value("pwd").toString(), value.toString());
            }
        }
    }
    return;
}
/**
 * @brief 某个socket断开,关闭前发送描述符给服务器
 * 
 */
void ClientSocket::DiscCon() {
    emit this->Discon(des);
    this->des = 0;
}
