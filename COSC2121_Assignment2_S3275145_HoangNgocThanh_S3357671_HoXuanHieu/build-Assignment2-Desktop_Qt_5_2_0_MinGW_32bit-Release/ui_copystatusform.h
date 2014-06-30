/********************************************************************************
** Form generated from reading UI file 'copystatusform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COPYSTATUSFORM_H
#define UI_COPYSTATUSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CopyStatusForm
{
public:
    QPushButton *okBtn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QDialog *CopyStatusForm)
    {
        if (CopyStatusForm->objectName().isEmpty())
            CopyStatusForm->setObjectName(QStringLiteral("CopyStatusForm"));
        CopyStatusForm->resize(303, 460);
        okBtn = new QPushButton(CopyStatusForm);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(200, 410, 75, 31));
        scrollArea = new QScrollArea(CopyStatusForm);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 40, 241, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 349));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 241, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(CopyStatusForm);

        QMetaObject::connectSlotsByName(CopyStatusForm);
    } // setupUi

    void retranslateUi(QDialog *CopyStatusForm)
    {
        CopyStatusForm->setWindowTitle(QApplication::translate("CopyStatusForm", "Dialog", 0));
        okBtn->setText(QApplication::translate("CopyStatusForm", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class CopyStatusForm: public Ui_CopyStatusForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COPYSTATUSFORM_H
