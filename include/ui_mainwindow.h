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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QWidget *page;
    QGridLayout *gridLayout_2;
    StartScreen *graphicsView;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
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
        stackedWidget->setStyleSheet(QStringLiteral("QStackedWidget {border-image: url(:images/metal.jpg) 0 0 0 0 stretch stretch;}"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        graphicsView = new StartScreen(page);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QStringLiteral("StartScreen {border-image: url(:images/metal.jpg) 0 0 0 0 stretch stretch;}"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setLineWidth(0);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setStyleSheet(QStringLiteral(""));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frame = new QFrame(page_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(300, 16777215));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 200));
        pushButton->setAutoFillBackground(true);

        verticalLayout->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 200));
        pushButton_2->setAutoFillBackground(true);

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 200));
        pushButton_3->setAutoFillBackground(true);

        verticalLayout->addWidget(pushButton_3);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Make a drink", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Scoreboard", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Admin", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
