#include "myregister.h"
#include "ui_myregister.h"

myRegister::myRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myRegister)
{
    ui->setupUi(this);

}

myRegister::~myRegister()
{
    delete ui;
}
