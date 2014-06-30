/********************************************************************************
** Form generated from reading UI file 'showallcollections.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWALLCOLLECTIONS_H
#define UI_SHOWALLCOLLECTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_showAllCollections
{
public:
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QPushButton *saveBtn;
    QPushButton *printpreviewBnt;
    QPushButton *printBtn;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;

    void setupUi(QDialog *showAllCollections)
    {
        if (showAllCollections->objectName().isEmpty())
            showAllCollections->setObjectName(QStringLiteral("showAllCollections"));
        showAllCollections->resize(738, 435);
        comboBox = new QComboBox(showAllCollections);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 131, 31));
        tableWidget = new QTableWidget(showAllCollections);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 80, 721, 301));
        saveBtn = new QPushButton(showAllCollections);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setGeometry(QRect(610, 40, 121, 31));
        printpreviewBnt = new QPushButton(showAllCollections);
        printpreviewBnt->setObjectName(QStringLiteral("printpreviewBnt"));
        printpreviewBnt->setGeometry(QRect(570, 390, 81, 31));
        printBtn = new QPushButton(showAllCollections);
        printBtn->setObjectName(QStringLiteral("printBtn"));
        printBtn->setGeometry(QRect(660, 390, 75, 31));
        lineEdit = new QLineEdit(showAllCollections);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 40, 441, 31));
        pushButton_2 = new QPushButton(showAllCollections);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 390, 81, 31));

        retranslateUi(showAllCollections);

        QMetaObject::connectSlotsByName(showAllCollections);
    } // setupUi

    void retranslateUi(QDialog *showAllCollections)
    {
        showAllCollections->setWindowTitle(QApplication::translate("showAllCollections", "Dialog", 0));
        saveBtn->setText(QApplication::translate("showAllCollections", "Search", 0));
        printpreviewBnt->setText(QApplication::translate("showAllCollections", "Print Preview", 0));
        printBtn->setText(QApplication::translate("showAllCollections", "Print", 0));
        pushButton_2->setText(QApplication::translate("showAllCollections", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class showAllCollections: public Ui_showAllCollections {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWALLCOLLECTIONS_H
