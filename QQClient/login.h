#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>
#include <mainwindow.h>
#include <map>
class MainWindow;
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
private:
     bool check();
private slots:
    void on_pushButton_clicked();

signals:
    void checkLoginsignal(QString account,QString pwd);

public:
    //是否在线
    static bool isOnline(QString username){
        auto it = mp.find(username);
        return it!= mp.end();
    }

    static void deleteOnline(QString username)
    {
        mp.erase(username);
    }
private:
    Ui::login *ui;
    static std::map<QString,MainWindow*> mp;
};

#endif // LOGIN_H
