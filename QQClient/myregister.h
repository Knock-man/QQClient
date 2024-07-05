#ifndef MYREGISTER_H
#define MYREGISTER_H

#include <QWidget>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include "login.h"
#define PORT 8110;
namespace Ui {
class myRegister;
}

class myRegister : public QWidget
{
    Q_OBJECT

public:
    explicit myRegister(QWidget *parent = nullptr);
    ~myRegister();
private slots:
    void on_pushButton_clicked();

private:
    void initNet();//初始化网络

private:
    Ui::myRegister *ui;
    //网络相关
    QString ipAddress = "127.0.0.1";
    int port = PORT;
    QTcpSocket *socket;
};

#endif // MYREGISTER_H
