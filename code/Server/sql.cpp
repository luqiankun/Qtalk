#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#    pragma execution_character_set("utf-8")
#endif
#include "sql.h"

#include <QDateTime>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <iostream>
using namespace std;
SQL::SQL(QObject* parent) : QObject(parent) { db = nullptr; }

bool SQL::InitSql() {
    if (QSqlDatabase::contains("ChatUsers")) {
        this->PrintStr("数据库已经连接，无需再次初始化");
        return true;
    }
    else {
        this->db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
        db->setDatabaseName("ChatUsers.db");
        if (db->open()) {
            this->Close();
            this->PrintStr("数据库初始化成功");
            return true;
        }
        else {
            this->PrintStr("数据库初始化失败");
            return false;
        }
    }
}

bool SQL::InitSql(QString ip, QString DbName, QString UserName, QString UserPWD) {
    //TODO: 自定义数据库
    return false;
}

bool SQL::Open() {
    if (db->isValid() && !db->isOpen()) {
        if (db->open()) {
            this->PrintStr("数据库开启成功");
            return true;
        }
        else {
            this->PrintStr("数据库开启失败");
            return false;
        }
    }
    else {
        this->PrintStr("数据库开启失败");
        return false;
    }
}

bool SQL::Close() {
    if (db->isValid() && db->open()) {
        QSqlQuery query;
        QString str = "delete from online_user";
        query.exec(str);
        db->close();
        this->PrintStr("数据库关闭成功");
        return true;
    }
    else {
        this->PrintStr("数据库关闭失败");
        return false;
    }
}

void SQL::PrintStr(string str) {
    QDateTime time = QDateTime::currentDateTime();
    string nowtime = time.toString().toLocal8Bit().toStdString();
    cout << nowtime + ">>" + QString::fromStdString(str).toLocal8Bit().toStdString() << endl;
}

bool SQL::Login(QString useName, QString userPwd) {
    if (!db->open()) {
        PrintStr("服务器数据库未打开,无法处理登录业务");

        return false;
    }
    else {
        QSqlQuery query;
        QString str = "select * from user_pwd where 昵称=? and 密码=?;";
        query.prepare(str);
        query.addBindValue(useName);
        query.addBindValue(userPwd);
        query.exec();
        QSqlRecord rec = query.record();
        if (!query.first()) {
            PrintStr("账号或密码不正确");
            return false;
        }
        else {
            QString str2 = "SELECT * FROM online_user WHERE 昵称=" + useName + ";";
            query.exec(str2);
            rec = query.record();
            if (!query.first()) {
                // TODO
                str2.clear();
                str2 ="insert into online_user (昵称) values(" + useName + ");";
                query.exec(str2);
                qDebug() << useName + "登录成功";
                return true;
            }
            else {
                PrintStr(useName.toStdString() + "登录失败,该账号已经登录");

                return false;
            }
        }
    }
}

bool SQL::Logout(QString useName) {
    if (!db->open()) {
        PrintStr("服务器数据库未打开,无法处理下线业务");
        return false;
    }
    else {
        QSqlQuery query;
        QString str = "select * from user_pwd where 昵称=\"" + useName + "\"";
        query.exec(str);
        QSqlRecord rec = query.record();
        if (!query.first()) {
            PrintStr("不存在该账号");
            return false;
        }
        else {
            QString str2 = "SELECT * FROM online_user WHERE 昵称=\"" + useName + "\"";
            query.exec(str2);
            if (query.first()) {
                // TODO
                str2.clear();
                str2 = "delete from online_user where 昵称=\"" + useName + "\"";
                query.exec(str2);
                PrintStr(useName.toStdString() + "下线成功");
                return true;
            }
            else {
                PrintStr(useName.toStdString() + "下线失败,该账号已经离线");

                return false;
            }
        }
    }
}

bool SQL::IsOnline(QString useName) {
    if (!db->open()) {
        PrintStr("服务器数据库未打开,无法处理查询业务");
        return false;
    }
    else {
        QSqlQuery query;
        QString str ="select * from online_user where 昵称=" + useName + ";";
        query.exec(str);
        if (!query.first()) {
            PrintStr(useName.toLocal8Bit().toStdString() + "不在线");
            return false;
        }
        else {
            PrintStr(useName.toStdString() + "在线");
            return true;
        }
    }
}

bool SQL::Logon(QString useName, QString userPwd) {
    if (!db->open()) {
        PrintStr("服务器数据库未打开,无法处理注册业务");
        return false;
    }
    else {
        if (useName == "" || userPwd == "") {
            PrintStr(useName.toStdString() + "注册失败,账号和密码不能为空");
            return false;
        }
        QSqlQuery query;
        QString str ="select * from user_pwd where 昵称=?;";
        query.prepare(str);
        query.addBindValue(useName);
        query.exec();
        if (query.first()) {
            PrintStr("已经存在该账号");
            return false;
        }
        else {
            QString str2 = "insert into user_pwd values(?,?,?);";

            query.clear();
            qDebug() << query.prepare(str2);
            query.addBindValue(useName);
            query.addBindValue(userPwd);
            query.addBindValue("");
            query.exec();
            QString str = "select * from user_pwd where 昵称=? and 密码=?;";
            query.clear();
            query.prepare(str);
            query.addBindValue(useName);
            query.addBindValue(userPwd);
            query.exec();
            if (query.first()) {
                // TODO
                PrintStr(useName.toStdString() + "注册成功");
                return true;
            }
            else {
                PrintStr(useName.toStdString() + "注册失败");
                return false;
            }
        }
    }
}

bool SQL::Upheadimg(QString useName, QString userPwd, QString imgdata) {
    if (!db->open()) {
        PrintStr("服务器数据库未打开,无法上传头像");
        return false;
    }
    else {
        QSqlQuery query;
        QString str = "update user_pwd set 头像=\"" + imgdata + "\" where 昵称=? and 密码=?;";

        query.prepare(str);
        query.addBindValue(useName);
        query.addBindValue(userPwd);
        //        qDebug() << str;
        if (query.exec())
            return true;
        else
            return false;
    }
}

QString SQL::HeadOf(QString useName, QString) {
    if (!db->open()) {
        PrintStr("服务器数据库未打开,无法处理注册业务");
        return "";
    }
    else {
        QString str = "select 头像 from user_pwd where 昵称=?;";
        QSqlQuery query;
        query.prepare(str);
        query.addBindValue(useName);
        if (query.exec()) {
            if (query.first()) {
                return query.value("头像").toString();
            }
            else {
                return "";
            }

        }
        else {
            return "";
        }
    }
}

QList<QString> SQL::OnlineList() {
    QList<QString> onlines;
    if (!db->open()) {
        PrintStr("服务器数据库未打开,无法处理注册业务");
        return onlines;
    }
    else {
        QSqlQuery query;
        QString str = "SELECT *"
            "FROM online_user;";
        query.exec(str);
        QSqlRecord rec;
        while (query.next()) {
            rec = query.record();
            int snamecol = rec.indexOf("昵称");
            QString value = rec.value(snamecol).toString();
            // qDebug() << value;
            onlines.push_back(value);
        }
        return onlines;
    }
}
