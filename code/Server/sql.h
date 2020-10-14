#ifndef SQL_H
#define SQL_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <iostream>

using namespace std;
class SQL : public QObject {
    Q_OBJECT
  public:
    explicit SQL(QObject* parent = nullptr);
    bool InitSql();  //默认初始化
    bool InitSql(QString ip, QString DbName, QString UserName, QString UserPWD);
    bool Open();
    bool Close();
    void PrintStr(string str);                                          //打印消息
    bool Login(QString useName, QString userPwd);                       //登录
    bool Logout(QString useName);                                       //下线
    bool IsOnline(QString useName);                                     //是否在线
    bool Logon(QString useName, QString userPwd);                       //注册
    bool Upheadimg(QString useName, QString userPwd, QString imgdata);  //上传头像
    QString HeadOf(QString useName, QString uesrPwd);                   //获取头像
    QList<QString> OnlineList();                                        //获取在线列表
  signals:
  private:
    QSqlDatabase* db;
};

#endif  // SQL_H
