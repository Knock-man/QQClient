#include "login.h"
#include "ui_login.h"

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
    QMessageBox::warning(this,"登录错误","账号或者密码错误，请重新输入");
    if(check())//登录失败
    {
        QMessageBox::warning(this,"登录错误","账号或者密码错误，请重新输入");
        return;
    }
    MainWindow mainwindow;
    mainwindow.show();
}
