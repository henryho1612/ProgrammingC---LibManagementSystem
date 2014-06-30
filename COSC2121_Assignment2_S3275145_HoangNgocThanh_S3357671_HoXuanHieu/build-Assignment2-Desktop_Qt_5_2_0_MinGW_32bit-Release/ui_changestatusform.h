/********************************************************************************
** Form generated from reading UI file 'changestatusform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESTATUSFORM_H
#define UI_CHANGESTATUSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeStatusForm
{
public:
    QComboBox *typeCBB;
    QLineEdit *searchF;
    QLabel *error;
    QPushButton *searchBtn;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *ChangeStatusForm)
    {
        if (ChangeStatusForm->objectName().isEmpty())
            ChangeStatusForm->setObjectName(QStringLiteral("ChangeStatusForm"));
        ChangeStatusForm->resize(572, 471);
        typeCBB = new QComboBox(ChangeStatusForm);
        typeCBB->setObjectName(QStringLiteral("typeCBB"));
        typeCBB->setGeometry(QRect(20, 40, 131, 31));
        searchF = new QLineEdit(ChangeStatusForm);
        searchF->setObjectName(QStringLiteral("searchF"));
        searchF->setGeometry(QRect(180, 40, 271, 31));
        error = new QLabel(ChangeStatusForm);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(180, 80, 271, 16));
        QFont font;
        font.setPointSize(10);
        error->setFont(font);
        searchBtn = new QPushButton(ChangeStatusForm);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        searchBtn->setGeometry(QRect(460, 40, 91, 31));
        tableWidget = new QTableWidget(ChangeStatusForm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 131, 531, 271));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        pushButton = new QPushButton(ChangeStatusForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(464, 422, 91, 31));

        retranslateUi(ChangeStatusForm);

        QMetaObject::connectSlotsByName(ChangeStatusForm);
    } // setupUi

    void retranslateUi(QDialog *ChangeStatusForm)
    {
        ChangeStatusForm->setWindowTitle(QApplication::translate("ChangeStatusForm", "Dialog", 0));
        error->setText(QString());
        searchBtn->setText(QApplication::translate("ChangeStatusForm", "Search", 0));
        pushButton->setText(QApplication::translate("ChangeStatusForm", "Confirm", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangeStatusForm: public Ui_ChangeStatusForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESTATUSFORM_H
