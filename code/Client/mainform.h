#ifndef MAINFORM_H
#define MAINFORM_H

#include <QAction>
#include <QEvent>
#include <QListWidgetItem>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTcpSocket>
#include <QWidget>

#include "chatform.h"
#include "login.h"
#include "tishi.h"
namespace Ui {
    class MainForm;
}

class MainForm : public QWidget {
    Q_OBJECT

  public:
    explicit MainForm(QWidget* parent = nullptr);
    ~MainForm();
    QJsonValue jsonValFromPixmap(const QPixmap& p);
    QPixmap pixmapFrom(const QJsonValue& val);
  signals:
    //发送给登录界面
    void IsConSer(bool);
    void Login_(bool);
    void Logon_(bool);
    //
  public slots:
    //登陆界面返回的消息
    void ShowMainForm();
    void LoginUser(QString, QString);
    void LogonUser(QString, QString);
    void Serverset(QString, int);
    //处理服务器返回的消息
    void ProcessNews();
    //聊天框的消息
    void CloseChatWidget(QString);
    void SendToSomeone(QString, QString);

  private slots:
    void on_usersList_itemDoubleClicked(QListWidgetItem* item);

    void on_closeAllBtn_clicked();

    void on_minBtn_clicked();

  private:
    Tishi* tishi=nullptr;
    QTimer* timer=nullptr;
    QMenu* menubar;
    QAction* closeAct;
    QAction* showmainForm;
    QSystemTrayIcon* tuoPan;
    QList<ChatForm*> ChatWidgets;
    Ui::MainForm* ui;
    QTcpSocket* client;
    Login* login;
    QString userName;
    QString pwd;
    bool IsPress = false;
    QPoint mouse;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
};

#endif  // MAINFORM_H
