/********************************************************************************
** Form generated from reading UI file 'returncopyform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURNCOPYFORM_H
#define UI_RETURNCOPYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ReturnCopyForm
{
public:
    QGroupBox *groupBox;
    QLabel *barcodeErr;
    QLineEdit *barcodeF;
    QLabel *label;
    QLabel *borrowerErr;
    QLineEdit *borrowerF;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *ReturnCopyForm)
    {
        if (ReturnCopyForm->objectName().isEmpty())
            ReturnCopyForm->setObjectName(QStringLiteral("ReturnCopyForm"));
        ReturnCopyForm->resize(474, 458);
        groupBox = new QGroupBox(ReturnCopyForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 301, 151));
        barcodeErr = new QLabel(groupBox);
        barcodeErr->setObjectName(QStringLiteral("barcodeErr"));
        barcodeErr->setGeometry(QRect(100, 50, 181, 31));
        QFont font;
        font.setPointSize(10);
        barcodeErr->setFont(font);
        barcodeF = new QLineEdit(groupBox);
        barcodeF->setObjectName(QStringLiteral("barcodeF"));
        barcodeF->setGeometry(QRect(100, 20, 181, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 81, 31));
        label->setFont(font);
        borrowerErr = new QLabel(groupBox);
        borrowerErr->setObjectName(QStringLiteral("borrowerErr"));
        borrowerErr->setGeometry(QRect(100, 110, 181, 31));
        borrowerErr->setFont(font);
        borrowerF = new QLineEdit(groupBox);
        borrowerF->setObjectName(QStringLiteral("borrowerF"));
        borrowerF->setGeometry(QRect(100, 80, 181, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 81, 31));
        label_2->setFont(font);
        tableWidget = new QTableWidget(ReturnCopyForm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 200, 451, 192));
        okBtn = new QPushButton(ReturnCopyForm);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(290, 410, 75, 31));
        cancelBtn = new QPushButton(ReturnCopyForm);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(380, 410, 75, 31));

        retranslateUi(ReturnCopyForm);

        QMetaObject::connectSlotsByName(ReturnCopyForm);
    } // setupUi

    void retranslateUi(QDialog *ReturnCopyForm)
    {
        ReturnCopyForm->setWindowTitle(QApplication::translate("ReturnCopyForm", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("ReturnCopyForm", "Return Copy Form", 0));
        barcodeErr->setText(QString());
        label->setText(QApplication::translate("ReturnCopyForm", "Barcode", 0));
        borrowerErr->setText(QString());
        borrowerF->setText(QString());
        label_2->setText(QApplication::translate("ReturnCopyForm", "Borrower Id", 0));
        okBtn->setText(QApplication::translate("ReturnCopyForm", "OK", 0));
        cancelBtn->setText(QApplication::translate("ReturnCopyForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ReturnCopyForm: public Ui_ReturnCopyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURNCOPYFORM_H
