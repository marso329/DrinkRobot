/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_passwordDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *password;
    QPushButton *ok;

    void setupUi(QDialog *passwordDialog)
    {
        if (passwordDialog->objectName().isEmpty())
            passwordDialog->setObjectName(QStringLiteral("passwordDialog"));
        passwordDialog->resize(190, 126);
        passwordDialog->setMaximumSize(QSize(200, 200));
        gridLayout = new QGridLayout(passwordDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(passwordDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        password = new QLineEdit(passwordDialog);
        password->setObjectName(QStringLiteral("password"));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password);

        ok = new QPushButton(passwordDialog);
        ok->setObjectName(QStringLiteral("ok"));

        verticalLayout->addWidget(ok);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(passwordDialog);

        QMetaObject::connectSlotsByName(passwordDialog);
    } // setupUi

    void retranslateUi(QDialog *passwordDialog)
    {
        passwordDialog->setWindowTitle(QApplication::translate("passwordDialog", "Login", Q_NULLPTR));
        label_2->setText(QApplication::translate("passwordDialog", "Password", Q_NULLPTR));
        ok->setText(QApplication::translate("passwordDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class passwordDialog: public Ui_passwordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
