﻿#include "login.h"
#include "ui_login.h"
//std::map<QString,MainWindow*> login::mp;
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

bool login::check()
{
   return true;
}
void login::on_pushButton_clicked()
{
    QString id = ui->account_lineEdit->text();
    QString password = ui->pwd_lineEdit->text();
   if(!check())//验证账号密码是否符合要求
   {
       QMessageBox::warning(this,u8"登录错误",u8"账号密码不能为空");
       return;
   }
   if(login::isOnline(id)){
       QMessageBox::warning(this,u8"登录错误",u8"用户已经登录");
       return;
   }
   MainWindow *mainwindow = new MainWindow(this,id,password);
   //connect(this, SIGNAL(checkLoginsignal(QString, QString)),
           //mainwindow, SLOT(checklogin(QString, QString)),Qt::UniqueConnection);
   mp[id]=mainwindow;
   //mainwindow->show();
   //emit checkLoginsignal(username, password);
   connect(mainwindow, &MainWindow::deleteuser, this, [&](QString username)
   {
       auto it = mp.find(username);
       if(it!=mp.end())
       {
           mp.erase(it);
       }
   });
}

void login::on_pushButton_2_clicked()
{
    myRegister* reg = new myRegister(this); // 若希望myRegister作为login的子窗口并随其生命周期管理，可保留this作为父对象，否则移除
    reg->setAttribute(Qt::WA_DeleteOnClose); // 保持此行，确保reg窗口关闭时释放资源
    reg->show(); // 显示注册窗口
    connect(reg, &QObject::destroyed, this, &login::show);
}
