/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "startscreen.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *startpage;
    QGridLayout *gridLayout_2;
    StartScreen *graphicsView;
    QWidget *mainpage;
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_7;
    QPushButton *make_a_drink;
    QSpacerItem *verticalSpacer;
    QPushButton *scoreboard;
    QSpacerItem *verticalSpacer_2;
    QPushButton *admin;
    QWidget *adminpage;
    QGridLayout *gridLayout_6;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QPushButton *add_ingredient;
    QPushButton *add_user;
    QPushButton *add_drink;
    QPushButton *set_levels;
    QPushButton *admin_back;
    QWidget *loginpage;
    QGridLayout *gridLayout_9;
    QFrame *frame_3;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *login_cancel;
    QPushButton *login_ok;
    QWidget *drinkpage;
    QGridLayout *gridLayout_11;
    QFrame *frame_4;
    QGridLayout *gridLayout_10;
    QPushButton *drink_back;
    QWidget *adduserpage;
    QGridLayout *gridLayout_13;
    QFrame *frame_5;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *name_input;
    QLabel *label_4;
    QLineEdit *pass_input;
    QRadioButton *admin_input;
    QPushButton *adduser_ok;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 662);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMaximumSize(QSize(3000, 3000));
        stackedWidget->setStyleSheet(QStringLiteral("QStackedWidget {border-image: url(:images/metal.jpg) 0 0 0 0 stretch stretch;}"));
        startpage = new QWidget();
        startpage->setObjectName(QStringLiteral("startpage"));
        startpage->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(startpage);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        graphicsView = new StartScreen(startpage);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QStringLiteral("StartScreen {border-image: url(:images/metal.jpg) 0 0 0 0 stretch stretch;}"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setLineWidth(0);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        stackedWidget->addWidget(startpage);
        mainpage = new QWidget();
        mainpage->setObjectName(QStringLiteral("mainpage"));
        mainpage->setStyleSheet(QStringLiteral(""));
        gridLayout_4 = new QGridLayout(mainpage);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frame = new QFrame(mainpage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        make_a_drink = new QPushButton(frame);
        make_a_drink->setObjectName(QStringLiteral("make_a_drink"));
        make_a_drink->setMinimumSize(QSize(200, 200));
        make_a_drink->setMaximumSize(QSize(200, 200));
        make_a_drink->setAutoFillBackground(true);

        gridLayout_7->addWidget(make_a_drink, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 1, 0, 1, 1);

        scoreboard = new QPushButton(frame);
        scoreboard->setObjectName(QStringLiteral("scoreboard"));
        scoreboard->setMinimumSize(QSize(200, 200));
        scoreboard->setMaximumSize(QSize(200, 200));
        scoreboard->setAutoFillBackground(true);

        gridLayout_7->addWidget(scoreboard, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 3, 0, 1, 1);

        admin = new QPushButton(frame);
        admin->setObjectName(QStringLiteral("admin"));
        admin->setMinimumSize(QSize(200, 200));
        admin->setMaximumSize(QSize(200, 200));
        admin->setAutoFillBackground(true);

        gridLayout_7->addWidget(admin, 4, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame, 0, 0, 1, 1);

        stackedWidget->addWidget(mainpage);
        adminpage = new QWidget();
        adminpage->setObjectName(QStringLiteral("adminpage"));
        gridLayout_6 = new QGridLayout(adminpage);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frame_2 = new QFrame(adminpage);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        add_ingredient = new QPushButton(frame_2);
        add_ingredient->setObjectName(QStringLiteral("add_ingredient"));
        add_ingredient->setMinimumSize(QSize(200, 200));
        add_ingredient->setMaximumSize(QSize(200, 200));

        gridLayout_5->addWidget(add_ingredient, 0, 0, 1, 1);

        add_user = new QPushButton(frame_2);
        add_user->setObjectName(QStringLiteral("add_user"));
        add_user->setMinimumSize(QSize(200, 200));
        add_user->setMaximumSize(QSize(200, 200));

        gridLayout_5->addWidget(add_user, 0, 1, 1, 1);

        add_drink = new QPushButton(frame_2);
        add_drink->setObjectName(QStringLiteral("add_drink"));
        add_drink->setMinimumSize(QSize(200, 200));
        add_drink->setMaximumSize(QSize(200, 200));

        gridLayout_5->addWidget(add_drink, 1, 0, 1, 1);

        set_levels = new QPushButton(frame_2);
        set_levels->setObjectName(QStringLiteral("set_levels"));
        set_levels->setMinimumSize(QSize(200, 200));
        set_levels->setMaximumSize(QSize(200, 200));

        gridLayout_5->addWidget(set_levels, 1, 1, 1, 1);

        admin_back = new QPushButton(frame_2);
        admin_back->setObjectName(QStringLiteral("admin_back"));
        admin_back->setMinimumSize(QSize(200, 200));
        admin_back->setMaximumSize(QSize(200, 200));

        gridLayout_5->addWidget(admin_back, 2, 1, 1, 1);


        gridLayout_6->addWidget(frame_2, 0, 0, 1, 1);

        stackedWidget->addWidget(adminpage);
        loginpage = new QWidget();
        loginpage->setObjectName(QStringLiteral("loginpage"));
        gridLayout_9 = new QGridLayout(loginpage);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        frame_3 = new QFrame(loginpage);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setMaximumSize(QSize(200, 200));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_3);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(frame_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout_8->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(frame_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        gridLayout_8->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        login_cancel = new QPushButton(frame_3);
        login_cancel->setObjectName(QStringLiteral("login_cancel"));

        gridLayout_8->addWidget(login_cancel, 2, 0, 1, 1);

        login_ok = new QPushButton(frame_3);
        login_ok->setObjectName(QStringLiteral("login_ok"));

        gridLayout_8->addWidget(login_ok, 2, 1, 1, 1);


        gridLayout_9->addWidget(frame_3, 0, 0, 1, 1);

        stackedWidget->addWidget(loginpage);
        drinkpage = new QWidget();
        drinkpage->setObjectName(QStringLiteral("drinkpage"));
        gridLayout_11 = new QGridLayout(drinkpage);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        frame_4 = new QFrame(drinkpage);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMaximumSize(QSize(250, 16777215));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_4);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        drink_back = new QPushButton(frame_4);
        drink_back->setObjectName(QStringLiteral("drink_back"));
        drink_back->setMinimumSize(QSize(100, 100));
        drink_back->setMaximumSize(QSize(100, 100));

        gridLayout_10->addWidget(drink_back, 0, 0, 1, 1);


        gridLayout_11->addWidget(frame_4, 0, 0, 1, 1);

        stackedWidget->addWidget(drinkpage);
        adduserpage = new QWidget();
        adduserpage->setObjectName(QStringLiteral("adduserpage"));
        gridLayout_13 = new QGridLayout(adduserpage);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        frame_5 = new QFrame(adduserpage);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMaximumSize(QSize(400, 16777215));
        frame_5->setFrameShape(QFrame::NoFrame);
        frame_5->setFrameShadow(QFrame::Plain);
        gridLayout_12 = new QGridLayout(frame_5);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        name_input = new QLineEdit(frame_5);
        name_input->setObjectName(QStringLiteral("name_input"));

        horizontalLayout_3->addWidget(name_input);

        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        pass_input = new QLineEdit(frame_5);
        pass_input->setObjectName(QStringLiteral("pass_input"));

        horizontalLayout_3->addWidget(pass_input);

        admin_input = new QRadioButton(frame_5);
        admin_input->setObjectName(QStringLiteral("admin_input"));

        horizontalLayout_3->addWidget(admin_input);

        adduser_ok = new QPushButton(frame_5);
        adduser_ok->setObjectName(QStringLiteral("adduser_ok"));

        horizontalLayout_3->addWidget(adduser_ok);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_12->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_13->addWidget(frame_5, 1, 0, 1, 1);

        stackedWidget->addWidget(adduserpage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        make_a_drink->setText(QApplication::translate("MainWindow", "Make a drink", Q_NULLPTR));
        scoreboard->setText(QApplication::translate("MainWindow", "Scoreboard", Q_NULLPTR));
        admin->setText(QApplication::translate("MainWindow", "Admin", Q_NULLPTR));
        add_ingredient->setText(QApplication::translate("MainWindow", "Add ingrediant", Q_NULLPTR));
        add_user->setText(QApplication::translate("MainWindow", "Add user", Q_NULLPTR));
        add_drink->setText(QApplication::translate("MainWindow", "Add drink", Q_NULLPTR));
        set_levels->setText(QApplication::translate("MainWindow", "Set levels and ingredients", Q_NULLPTR));
        admin_back->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Username:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Password:", Q_NULLPTR));
        login_cancel->setText(QApplication::translate("MainWindow", "cancel", Q_NULLPTR));
        login_ok->setText(QApplication::translate("MainWindow", "ok", Q_NULLPTR));
        drink_back->setText(QApplication::translate("MainWindow", "back", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Pass:", Q_NULLPTR));
        admin_input->setText(QApplication::translate("MainWindow", "Admin", Q_NULLPTR));
        adduser_ok->setText(QApplication::translate("MainWindow", "ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
