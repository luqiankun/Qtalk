#ifndef FORM_H
#define FORM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Form;
}
QT_END_NAMESPACE

class Login : public QWidget {
  Q_OBJECT

 public:
  Login(QWidget *parent = nullptr);
  ~Login();
  void First();
 signals:
  void ServerSet(QString, int);
  void LoginUser(QString, QString);
  void LogonUser(QString, QString);
  void ShowMainForm();
  void CloseAll();
 public slots:
  void IsConser(bool);
  void Login_(bool);
  void Logon_(bool);

 private slots:
  void on_setokBtn_clicked();

  void on_pushButton_6_clicked();

  void on_loginBtn_clicked();

  void on_userBtn_clicked();

  void on_setBtn_clicked();

  void on_logonBtn_clicked();

 private:
  bool IsJiyiUser = false;
  Ui::Form *ui;
  QPoint mouse;
  bool IsPress = false;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
};
#endif  // FORM_H
