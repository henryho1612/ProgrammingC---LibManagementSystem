/********************************************************************************
** Form generated from reading UI file 'addborrowerform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBORROWERFORM_H
#define UI_ADDBORROWERFORM_H

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

QT_BEGIN_NAMESPACE

class Ui_AddBorrowerForm
{
public:
    QGroupBox *groupBox;
    QLabel *label_5;
    QComboBox *roleCBB;
    QLabel *label_4;
    QLineEdit *bidF;
    QLineEdit *mobileF;
    QLineEdit *nameF;
    QComboBox *departmentCBB;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *bidErr;
    QLabel *nameErr;
    QLabel *mobileErr;
    QGroupBox *groupBox_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AddBorrowerForm)
    {
        if (AddBorrowerForm->objectName().isEmpty())
            AddBorrowerForm->setObjectName(QStringLiteral("AddBorrowerForm"));
        AddBorrowerForm->resize(347, 482);
        QFont font;
        font.setPointSize(10);
        AddBorrowerForm->setFont(font);
        groupBox = new QGroupBox(AddBorrowerForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 331, 361));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 290, 71, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_5->setFont(font2);
        roleCBB = new QComboBox(groupBox);
        roleCBB->setObjectName(QStringLiteral("roleCBB"));
        roleCBB->setGeometry(QRect(120, 171, 161, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 230, 81, 31));
        label_4->setFont(font2);
        bidF = new QLineEdit(groupBox);
        bidF->setObjectName(QStringLiteral("bidF"));
        bidF->setGeometry(QRect(120, 40, 161, 31));
        mobileF = new QLineEdit(groupBox);
        mobileF->setObjectName(QStringLiteral("mobileF"));
        mobileF->setGeometry(QRect(120, 290, 161, 31));
        nameF = new QLineEdit(groupBox);
        nameF->setObjectName(QStringLiteral("nameF"));
        nameF->setGeometry(QRect(120, 109, 161, 31));
        departmentCBB = new QComboBox(groupBox);
        departmentCBB->setObjectName(QStringLiteral("departmentCBB"));
        departmentCBB->setGeometry(QRect(120, 231, 161, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 71, 31));
        label_2->setFont(font2);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 71, 31));
        label->setFont(font2);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 71, 31));
        label_3->setFont(font2);
        bidErr = new QLabel(groupBox);
        bidErr->setObjectName(QStringLiteral("bidErr"));
        bidErr->setGeometry(QRect(120, 80, 161, 16));
        bidErr->setFont(font2);
        nameErr = new QLabel(groupBox);
        nameErr->setObjectName(QStringLiteral("nameErr"));
        nameErr->setGeometry(QRect(120, 150, 161, 16));
        nameErr->setFont(font2);
        mobileErr = new QLabel(groupBox);
        mobileErr->setObjectName(QStringLiteral("mobileErr"));
        mobileErr->setGeometry(QRect(120, 330, 161, 16));
        mobileErr->setFont(font2);
        groupBox_2 = new QGroupBox(AddBorrowerForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(140, 410, 191, 61));
        okBtn = new QPushButton(groupBox_2);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(10, 20, 81, 31));
        cancelBtn = new QPushButton(groupBox_2);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(100, 20, 81, 31));

        retranslateUi(AddBorrowerForm);

        QMetaObject::connectSlotsByName(AddBorrowerForm);
    } // setupUi

    void retranslateUi(QDialog *AddBorrowerForm)
    {
        AddBorrowerForm->setWindowTitle(QApplication::translate("AddBorrowerForm", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("AddBorrowerForm", "ADD NEW BORROWER", 0));
        label_5->setText(QApplication::translate("AddBorrowerForm", "Mobile", 0));
        label_4->setText(QApplication::translate("AddBorrowerForm", "Department", 0));
        mobileF->setText(QString());
        nameF->setText(QString());
        label_2->setText(QApplication::translate("AddBorrowerForm", "Name", 0));
        label->setText(QApplication::translate("AddBorrowerForm", "Brrower ID", 0));
        label_3->setText(QApplication::translate("AddBorrowerForm", "Role", 0));
        bidErr->setText(QString());
        nameErr->setText(QString());
        mobileErr->setText(QString());
        groupBox_2->setTitle(QString());
        okBtn->setText(QApplication::translate("AddBorrowerForm", "OK", 0));
        cancelBtn->setText(QApplication::translate("AddBorrowerForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddBorrowerForm: public Ui_AddBorrowerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBORROWERFORM_H
