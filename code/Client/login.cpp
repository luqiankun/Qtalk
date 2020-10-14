#include "login.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#    pragma execution_character_set("utf-8")
#endif
#include <QBitmap>
#include <QCryptographicHash>
#include <QMouseEvent>
#include <QPainter>
#include <QSettings>
#include <iostream>

#include "ui_login.h"

Login::Login(QWidget* parent) : QWidget(parent), ui(new Ui::Form) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    setWindowIcon(QIcon(":/img/logo.png"));
    QSettings* Inifile = new QSettings("user.ini", QSettings::IniFormat);
    ui->Portlineedit->setText(Inifile->value("settings/Port").toString());
    ui->IPlineedit->setText(Inifile->value("settings/Ip").toString());
    //记忆账号图标初始化
    if (Inifile->value("settings/Jizhu").toString() == "true") {
        std::cout << Inifile->value("settings/Jizhu").toString().toStdString();
        ui->userBtn->setStyleSheet(QString::fromLocal8Bit("border-image:url(:/img/2.png)"));
        ui->userLineedit->setText(Inifile->value("settings/user").toString());
    } else {
        std::cout << Inifile->value("settings/Jizhu").toString().toStdString();
        ui->userBtn->setStyleSheet(QString::fromLocal8Bit("border-image:url(:/img/1.png)"));
    }
    //
    connect(ui->pwdLineedit, &QLineEdit::returnPressed, this, [&] { this->on_loginBtn_clicked(); });
    ui->loginBtn->setEnabled(false);
    ui->logonBtn->setEnabled(false);
    this->resize(400, 330);
    //测试用
    //圆角
    QBitmap bmp(this->size());

    bmp.fill();

    QPainter p(&bmp);

    p.setPen(Qt::NoPen);

    p.setBrush(Qt::black);

    p.drawRoundedRect(bmp.rect(), 17, 17);

    setMask(bmp);
}

Login::~Login() { delete ui; }

void Login::First() { emit this->ServerSet(ui->IPlineedit->text().toLocal8Bit(), ui->Portlineedit->text().toInt()); }

void Login::IsConser(bool p) {
    if (p) {
        this->ui->statusLabel->setText("服务器已连接");
        ui->loginBtn->setEnabled(true);
        ui->logonBtn->setEnabled(true);
    } else {
        this->ui->statusLabel->setText("服务器未连接");
        ui->loginBtn->setEnabled(false);
        ui->logonBtn->setEnabled(false);
    }
}

void Login::Login_(bool p) {
    if (p) {
        emit ShowMainForm();
        this->close();
    } else {
        ui->statusLabel->setText("登录失败");
    }
}

void Login::Logon_(bool p) {
    if (p) {
        ui->statusLabel->setText("注册成功，请登录");
    } else {
        ui->statusLabel->setText("注册失败");
    }
}

void Login::on_setokBtn_clicked() {
    emit this->ServerSet(ui->IPlineedit->text().toLocal8Bit(), ui->Portlineedit->text().toInt());
    QSettings* Inifile = new QSettings("user.ini", QSettings::IniFormat);
    Inifile->setValue("settings/Ip", ui->IPlineedit->text().toLocal8Bit());
    Inifile->setValue("settings/Port", ui->Portlineedit->text().toLocal8Bit());
    this->resize(400, 330);
    ui->setokBtn->hide();
    ui->IPlabel->hide();
    ui->IPlineedit->hide();
    ui->Portlabel->hide();
    ui->Portlineedit->hide();
    QBitmap bmp(this->size());

    bmp.fill();

    QPainter p(&bmp);

    p.setPen(Qt::NoPen);

    p.setBrush(Qt::black);

    p.drawRoundedRect(bmp.rect(), 17, 17);

    setMask(bmp);
    update();
}

void Login::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        this->IsPress = true;
        this->mouse = event->globalPos() - this->pos();
    }
}

void Login::mouseMoveEvent(QMouseEvent* event) {
    if (this->IsPress)
        this->move(event->globalPos() - this->mouse);
}

void Login::mouseReleaseEvent(QMouseEvent*) {
    this->mouse = QPoint();
    this->IsPress = false;
}

void Login::on_pushButton_6_clicked() {
    QApplication::exit();
    //    emit CloseAll();
    //    this->close();
}

void Login::on_loginBtn_clicked() {
    emit LoginUser(ui->userLineedit->text(),
                   QCryptographicHash::hash(ui->pwdLineedit->text().toUtf8(), QCryptographicHash::Md5));
    std::cout << ui->userLineedit->text().toLocal8Bit().toStdString() << std::endl;
    if (IsJiyiUser) {
        QSettings* Inifile = new QSettings("user.ini", QSettings::IniFormat);
        Inifile->setValue("settings/user", ui->userLineedit->text());
        Inifile->setValue("settings/Jizhu", "true");
    } else {
        QSettings* Inifile = new QSettings("user.ini", QSettings::IniFormat);
        Inifile->setValue("settings/user", "");
        Inifile->setValue("settings/Jizhu", "false");
    }
}

void Login::on_userBtn_clicked() {
    if (IsJiyiUser) {
        IsJiyiUser = !IsJiyiUser;
        ui->userBtn->setStyleSheet(QString::fromLocal8Bit("border-image:url(:/img/1.png)"));
        QSettings* Inifile = new QSettings("user.ini", QSettings::IniFormat);
        Inifile->setValue("settings/Jizhu", "false");
    } else {
        ui->userBtn->setStyleSheet(QString::fromLocal8Bit("border-image:url(:/img/2.png)"));
        IsJiyiUser = !IsJiyiUser;
        QSettings* Inifile = new QSettings("user.ini", QSettings::IniFormat);
        Inifile->setValue("settings/Jizhu", "true");
    }
}

void Login::on_setBtn_clicked() {
    if (this->height() != 500) {
        this->resize(400, 500);
        QBitmap bmp(this->size());

        bmp.fill();

        QPainter p(&bmp);

        p.setPen(Qt::NoPen);

        p.setBrush(Qt::black);

        p.drawRoundedRect(bmp.rect(), 17, 17);

        setMask(bmp);
        ui->setokBtn->show();
        ui->IPlabel->show();
        ui->IPlineedit->show();
        ui->Portlabel->show();
        ui->Portlineedit->show();
    } else {
        this->resize(400, 330);
        QBitmap bmp(this->size());

        bmp.fill();

        QPainter p(&bmp);

        p.setPen(Qt::NoPen);

        p.setBrush(Qt::black);

        p.drawRoundedRect(bmp.rect(), 17, 17);

        setMask(bmp);
        ui->setokBtn->hide();
        ui->IPlabel->hide();
        ui->IPlineedit->hide();
        ui->Portlabel->hide();
        ui->Portlineedit->hide();
    }
}

void Login::on_logonBtn_clicked() {
    if (ui->pwdLineedit->text().length() < 8 || ui->userLineedit->text() < 4) {
        ui->statusLabel->setText("账号或密码长度太小");
        return;
    }
    emit LogonUser(ui->userLineedit->text(),
                   QCryptographicHash::hash(ui->pwdLineedit->text().toLocal8Bit(), QCryptographicHash::Md5));
}
