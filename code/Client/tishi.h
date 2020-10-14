#ifndef TISHI_H
#define TISHI_H

#include <QTimer>
#include <QWidget>
namespace Ui {
class Tishi;
}

class Tishi : public QWidget {
  Q_OBJECT

 public:
  explicit Tishi(QString str = "");
  ~Tishi();
  void SHOW();
 private slots:
  void on_noBtn_clicked();

  void on_okBtn_clicked();
  void Man_show();

 private:
  int nWidth;
  int nHeight;
  QString ID;
  Ui::Tishi *ui;
  QTimer *timer;
  int m = 0;
 signals:
  void See(QString);
};

#endif  // TISHI_H
