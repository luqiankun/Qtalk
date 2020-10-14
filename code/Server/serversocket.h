#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <iostream>

#include "clientsocket.h"
#include "sql.h"
using namespace std;
class ServerSocket : public QTcpServer {
    Q_OBJECT
  public:
    ServerSocket();
    QList<ClientSocket*>* conList;
    //  QList<ClientSocket> *onlineList;
    QMap<int, QString>* onlineUsers;
    void PrintStr(string str);  //打印消息
  public slots:
    void Discon(int);                           //断开信号,并判断是否需要执行下线操作
    void Login(int, QString, QString);          //登录
    void Logon(int, QString, QString);          //注册
    void Logout(int, QString);                  //离线
    void Sendnews(int, QString, QString);       //发送消息给好友
    void CLoseServer();                         //关闭服务器
    void SendUsers(int);                        //发送在线列表
    void Upheadimg(QString, QString, QString);  //上传头像
  protected:
    void incomingConnection(qintptr handle) override;
    SQL* sql;
};

#endif  // SERVERSOCKET_H
