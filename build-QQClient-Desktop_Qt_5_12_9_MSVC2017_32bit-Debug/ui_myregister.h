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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myRegister
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QLineEdit *pwd_lineEdit;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *user_lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *myRegister)
    {
        if (myRegister->objectName().isEmpty())
            myRegister->setObjectName(QString::fromUtf8("myRegister"));
        myRegister->resize(244, 153);
        widget = new QWidget(myRegister);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 221, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        pwd_lineEdit = new QLineEdit(widget);
        pwd_lineEdit->setObjectName(QString::fromUtf8("pwd_lineEdit"));

        gridLayout->addWidget(pwd_lineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        user_lineEdit = new QLineEdit(widget);
        user_lineEdit->setObjectName(QString::fromUtf8("user_lineEdit"));

        gridLayout->addWidget(user_lineEdit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(myRegister);

        QMetaObject::connectSlotsByName(myRegister);
    } // setupUi

    void retranslateUi(QWidget *myRegister)
    {
        myRegister->setWindowTitle(QApplication::translate("myRegister", "Form", nullptr));
        label->setText(QApplication::translate("myRegister", "\347\231\273\345\275\225", nullptr));
        label_3->setText(QApplication::translate("myRegister", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("myRegister", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("myRegister", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myRegister: public Ui_myRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYREGISTER_H
