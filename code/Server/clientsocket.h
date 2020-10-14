#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <QObject>
#include <QTcpSocket>

class ClientSocket : public QTcpSocket {
    Q_OBJECT
  public:
    int des;
    ClientSocket();  
  signals:
    void Discon(int);                           //断开信号
    void Login(int, QString, QString);          //登录
    void Logon(int, QString, QString);          //注册
    void Logout(int, QString);                  //离线
    void Sendnews(int, QString, QString);       //发送消息给好友
    void SendUser(int);                         //发送在线列表
    void Upheadimg(QString, QString, QString);  //上传头像
  private slots:
    void DataRece();  //接收
    void DiscCon();   //断开
};

#endif  // CLIENTSOCKET_H
