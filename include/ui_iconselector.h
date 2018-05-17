/********************************************************************************
** Form generated from reading UI file 'iconselector.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICONSELECTOR_H
#define UI_ICONSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iconselector_dialog
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QFrame *frame;

    void setupUi(QDialog *iconselector_dialog)
    {
        if (iconselector_dialog->objectName().isEmpty())
            iconselector_dialog->setObjectName(QStringLiteral("iconselector_dialog"));
        iconselector_dialog->resize(480, 600);
        iconselector_dialog->setMinimumSize(QSize(0, 0));
        iconselector_dialog->setMaximumSize(QSize(480, 800));
        gridLayout = new QGridLayout(iconselector_dialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(iconselector_dialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 460, 580));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 0));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);


        retranslateUi(iconselector_dialog);

        QMetaObject::connectSlotsByName(iconselector_dialog);
    } // setupUi

    void retranslateUi(QDialog *iconselector_dialog)
    {
        iconselector_dialog->setWindowTitle(QApplication::translate("iconselector_dialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class iconselector_dialog: public Ui_iconselector_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICONSELECTOR_H
