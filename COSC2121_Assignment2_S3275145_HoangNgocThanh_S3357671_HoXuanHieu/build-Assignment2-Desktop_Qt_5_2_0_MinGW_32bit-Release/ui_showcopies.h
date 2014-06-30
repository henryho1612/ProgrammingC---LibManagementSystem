/********************************************************************************
** Form generated from reading UI file 'showcopies.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWCOPIES_H
#define UI_SHOWCOPIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_showCopies
{
public:
    QTableWidget *tableWidget;
    QPushButton *searchBtn;
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QPushButton *previewBtn;
    QPushButton *printBtn;
    QPushButton *saveBtn;

    void setupUi(QDialog *showCopies)
    {
        if (showCopies->objectName().isEmpty())
            showCopies->setObjectName(QStringLiteral("showCopies"));
        showCopies->resize(741, 421);
        tableWidget = new QTableWidget(showCopies);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 60, 721, 301));
        searchBtn = new QPushButton(showCopies);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        searchBtn->setGeometry(QRect(610, 20, 121, 31));
        textEdit = new QTextEdit(showCopies);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(160, 20, 441, 31));
        comboBox = new QComboBox(showCopies);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 20, 131, 31));
        previewBtn = new QPushButton(showCopies);
        previewBtn->setObjectName(QStringLiteral("previewBtn"));
        previewBtn->setGeometry(QRect(560, 370, 81, 31));
        printBtn = new QPushButton(showCopies);
        printBtn->setObjectName(QStringLiteral("printBtn"));
        printBtn->setGeometry(QRect(650, 370, 81, 31));
        saveBtn = new QPushButton(showCopies);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setGeometry(QRect(470, 370, 75, 31));

        retranslateUi(showCopies);

        QMetaObject::connectSlotsByName(showCopies);
    } // setupUi

    void retranslateUi(QDialog *showCopies)
    {
        showCopies->setWindowTitle(QApplication::translate("showCopies", "Dialog", 0));
        searchBtn->setText(QApplication::translate("showCopies", "Search", 0));
        previewBtn->setText(QApplication::translate("showCopies", "Print Preview", 0));
        printBtn->setText(QApplication::translate("showCopies", "Print", 0));
        saveBtn->setText(QApplication::translate("showCopies", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class showCopies: public Ui_showCopies {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWCOPIES_H
