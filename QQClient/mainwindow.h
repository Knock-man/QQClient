#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include "login.h"
#define PORT 8110;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,QString id="",QString pwd="");
    ~MainWindow();

private:
    void initNet();//初始化网络
    void checklogin();
signals:
    //关闭窗口信号
    void deleteuser(QString id);

protected:
    void closeEvent(QCloseEvent *event) override;
private:
    Ui::MainWindow *ui;
    QString m_id;
    QString m_pwd;
    //网络相关
    QString ipAddress = "127.0.0.1";
    int port = PORT;
    QTcpSocket *socket;
};
#endif // MAINWINDOW_H
