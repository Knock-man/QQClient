#include "mainwindow.h"
#include "ui_mainwindow.h"

enum EsMsgType{
    LOGIN_MSG = 1, //登录消息
    LOGIN_MSG_ACK, //登录响应消息
    LOGINOUT_MSG, //注销消息
    REG_MSG, //注册消息
    REG_MSG_ACK, //注册响应消息
    ONE_CHAT_MSG, //聊天消息
    ADD_FRIEND_MSG, //添加好友消息

    CREATE_GROUP_MSG, //创建群组
    ADD_GROUP_MSG, //加入群组
    GROUP_CHAT_MSG, //群聊天

};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //连接服务器
    initNet();

}

MainWindow::~MainWindow()
{
    socket->close();
    delete ui;
}

//验证用户是否存在
void MainWindow::checklogin(QString id,QString pwd)
{
    this->id = id;
    this->pwd = pwd;
    qDebug()<<u8"账号"<<id<<u8"密码"<<pwd;
    // 构建包含文件内容的 JSON 对象
    QJsonObject json;
    json["msgid"] = LOGIN_MSG;
    json["id"] = id.toInt();
    json["password"] = pwd;
    // 将 JSON 对象转换为 JSON字符串
    QJsonDocument doc(json);
    QByteArray jsonData = doc.toJson();
    // 添加自定义的结束标记
    //jsonData.append("END_OF_JSON");
    socket->write(jsonData);
    socket->flush();  // 确保数据被发送

    //接收数据
    connect(socket, &QTcpSocket::readyRead,this,[&](){
        QByteArray receivedData = socket->readAll();
        qDebug() << "Received data:" << receivedData;

        QJsonParseError jsonError;
        QJsonDocument doc = QJsonDocument::fromJson(receivedData, &jsonError);
        if (jsonError.error != QJsonParseError::NoError) {
            qDebug() << "Error parsing JSON data:" << jsonError.errorString();
            return;
        }

        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            if (obj["errno"].toInt() != 0) {
                if(obj["errno"].toInt()==2){//已经登录
                    socket->close();
                    //login::deleteOnline(id);
                    return;
                }
                QMessageBox::warning(nullptr,u8"登录错误",obj["errmsg"].toString());
                socket->close();
                login::deleteOnline(id);
            } else {
                show();
                //socket->close();
                qDebug() << u8"登录成功";
            }
        }

    });

}
void MainWindow::closeEvent(QCloseEvent *event)
{
    socket->close();
    login::deleteOnline(id);
    //event->accept();
}
void MainWindow::initNet()
{
    socket = new QTcpSocket(this);
    //连接网络
    socket->connectToHost(ipAddress, port);
    if (socket->waitForConnected()) {
        qDebug() << "Connected to the server";

        // 在这里可以进行数据的发送和接收
    } else {
        qDebug() << "Failed to connect to the server: " << socket->errorString();
    }
}
