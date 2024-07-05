#ifndef MYREGISTER_H
#define MYREGISTER_H

#include <QWidget>

namespace Ui {
class myRegister;
}

class myRegister : public QWidget
{
    Q_OBJECT

public:
    explicit myRegister(QWidget *parent = nullptr);
    ~myRegister();

private:
    Ui::myRegister *ui;
};

#endif // MYREGISTER_H
