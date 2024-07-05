/********************************************************************************
** Form generated from reading UI file 'myregister.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYREGISTER_H
#define UI_MYREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myRegister
{
public:

    void setupUi(QWidget *myRegister)
    {
        if (myRegister->objectName().isEmpty())
            myRegister->setObjectName(QString::fromUtf8("myRegister"));
        myRegister->resize(300, 222);

        retranslateUi(myRegister);

        QMetaObject::connectSlotsByName(myRegister);
    } // setupUi

    void retranslateUi(QWidget *myRegister)
    {
        myRegister->setWindowTitle(QApplication::translate("myRegister", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myRegister: public Ui_myRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYREGISTER_H
