/********************************************************************************
** Form generated from reading UI file 'borrowcopyform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWCOPYFORM_H
#define UI_BORROWCOPYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_BorrowCopyForm
{
public:
    QGroupBox *groupBox;
    QLineEdit *barcodeF;
    QLabel *bidErr;
    QLabel *label_2;
    QLineEdit *bidF;
    QLabel *label;
    QLabel *barcodeErr;
    QLabel *label_3;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *BorrowCopyForm)
    {
        if (BorrowCopyForm->objectName().isEmpty())
            BorrowCopyForm->setObjectName(QStringLiteral("BorrowCopyForm"));
        BorrowCopyForm->resize(635, 511);
        groupBox = new QGroupBox(BorrowCopyForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 301, 191));
        barcodeF = new QLineEdit(groupBox);
        barcodeF->setObjectName(QStringLiteral("barcodeF"));
        barcodeF->setGeometry(QRect(120, 90, 141, 31));
        QFont font;
        font.setPointSize(10);
        barcodeF->setFont(font);
        bidErr = new QLabel(groupBox);
        bidErr->setObjectName(QStringLiteral("bidErr"));
        bidErr->setGeometry(QRect(120, 60, 141, 21));
        bidErr->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 71, 21));
        label_2->setFont(font);
        bidF = new QLineEdit(groupBox);
        bidF->setObjectName(QStringLiteral("bidF"));
        bidF->setGeometry(QRect(120, 30, 141, 31));
        bidF->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 71, 21));
        label->setFont(font);
        barcodeErr = new QLabel(groupBox);
        barcodeErr->setObjectName(QStringLiteral("barcodeErr"));
        barcodeErr->setGeometry(QRect(120, 120, 141, 21));
        barcodeErr->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 150, 71, 21));
        label_3->setFont(font);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 150, 69, 22));
        tableWidget = new QTableWidget(BorrowCopyForm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 230, 611, 221));
        pushButton = new QPushButton(BorrowCopyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 460, 81, 31));
        pushButton_2 = new QPushButton(BorrowCopyForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(540, 460, 81, 31));

        retranslateUi(BorrowCopyForm);

        QMetaObject::connectSlotsByName(BorrowCopyForm);
    } // setupUi

    void retranslateUi(QDialog *BorrowCopyForm)
    {
        BorrowCopyForm->setWindowTitle(QApplication::translate("BorrowCopyForm", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("BorrowCopyForm", "GroupBox", 0));
        bidErr->setText(QString());
        label_2->setText(QApplication::translate("BorrowCopyForm", "Barcode", 0));
        label->setText(QApplication::translate("BorrowCopyForm", "Borrower ID", 0));
        barcodeErr->setText(QString());
        label_3->setText(QApplication::translate("BorrowCopyForm", "Num Days", 0));
        pushButton->setText(QApplication::translate("BorrowCopyForm", "OK", 0));
        pushButton_2->setText(QApplication::translate("BorrowCopyForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class BorrowCopyForm: public Ui_BorrowCopyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWCOPYFORM_H
