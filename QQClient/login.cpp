#include "login.h"
#include "ui_login.h"
std::map<QString,MainWindow*> login::mp;
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
    QString username = ui->account_lineEdit->text();
    QString password = ui->pwd_lineEdit->text();
   if(!check())//验证账号密码是否符合要求
   {
       QMessageBox::warning(this,u8"登录错误",u8"账号或者密码错误，请重新输入");
       return;
   }
   if(!login::isOnline(username))
   {
       MainWindow *mainwindow = new MainWindow(this);
       connect(this, SIGNAL(checkLoginsignal(QString, QString)),
               mainwindow, SLOT(checklogin(QString, QString)),Qt::UniqueConnection);
       mp[username]=mainwindow;
       emit checkLoginsignal(username, password);
   }

}
