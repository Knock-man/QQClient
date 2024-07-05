#include "myregister.h"
#include "ui_myregister.h"

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
myRegister::myRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myRegister)
{
    ui->setupUi(this);
    setWindowTitle(u8"用户注册");
    initNet();

}

myRegister::~myRegister()
{
    delete ui;
    socket->close();
}

void myRegister::initNet()
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

void myRegister::on_pushButton_clicked()
{
    if(ui->user_lineEdit->text().isEmpty()||ui->pwd_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(nullptr,u8"注册失败",u8"用户名或密码不能为空");
        return;
    }
    QJsonObject json;
    json["msgid"] = REG_MSG;
    json["name"] = ui->user_lineEdit->text();
    json["password"] = ui->pwd_lineEdit->text();
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
                QMessageBox::warning(nullptr,u8"注册失败",u8"用户已存在，请直接登录");
                socket->close();
                hide();
            } else {
                double id = obj["id"].toDouble();
                QString infor = u8"请记住账号信息： 账号:"+QString::number(id)+u8" 密码:"+ui->pwd_lineEdit->text();
                QMessageBox::StandardButton result = QMessageBox::information(nullptr,u8"注册成功",infor);
                if(result==QMessageBox::Ok)
                {
                    hide();
                    socket->close();
                }
            }
        }

    });
}
