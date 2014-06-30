/********************************************************************************
** Form generated from reading UI file 'borrowerform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWERFORM_H
#define UI_BORROWERFORM_H

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

class Ui_BorrowerForm
{
public:
    QPushButton *searchBtn;
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QTextEdit *textEdit;
    QPushButton *previewBtn;
    QPushButton *printBtn;
    QPushButton *saveBtn;

    void setupUi(QDialog *BorrowerForm)
    {
        if (BorrowerForm->objectName().isEmpty())
            BorrowerForm->setObjectName(QStringLiteral("BorrowerForm"));
        BorrowerForm->resize(742, 444);
        searchBtn = new QPushButton(BorrowerForm);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        searchBtn->setGeometry(QRect(610, 30, 121, 31));
        tableWidget = new QTableWidget(BorrowerForm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 70, 721, 301));
        comboBox = new QComboBox(BorrowerForm);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 131, 31));
        textEdit = new QTextEdit(BorrowerForm);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(160, 30, 441, 31));
        previewBtn = new QPushButton(BorrowerForm);
        previewBtn->setObjectName(QStringLiteral("previewBtn"));
        previewBtn->setGeometry(QRect(560, 400, 81, 31));
        printBtn = new QPushButton(BorrowerForm);
        printBtn->setObjectName(QStringLiteral("printBtn"));
        printBtn->setGeometry(QRect(650, 400, 81, 31));
        saveBtn = new QPushButton(BorrowerForm);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setGeometry(QRect(474, 400, 81, 31));

        retranslateUi(BorrowerForm);

        QMetaObject::connectSlotsByName(BorrowerForm);
    } // setupUi

    void retranslateUi(QDialog *BorrowerForm)
    {
        BorrowerForm->setWindowTitle(QApplication::translate("BorrowerForm", "Dialog", 0));
        searchBtn->setText(QApplication::translate("BorrowerForm", "Search", 0));
        previewBtn->setText(QApplication::translate("BorrowerForm", "Preview", 0));
        printBtn->setText(QApplication::translate("BorrowerForm", "Print", 0));
        saveBtn->setText(QApplication::translate("BorrowerForm", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class BorrowerForm: public Ui_BorrowerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWERFORM_H
