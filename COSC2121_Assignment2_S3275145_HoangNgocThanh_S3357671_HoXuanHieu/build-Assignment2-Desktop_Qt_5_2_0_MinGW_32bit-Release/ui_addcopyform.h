/********************************************************************************
** Form generated from reading UI file 'addcopyform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOPYFORM_H
#define UI_ADDCOPYFORM_H

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

class Ui_AddCopyForm
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *cidF;
    QLabel *label_2;
    QComboBox *copiesCBB;
    QLabel *cidErr;
    QGroupBox *groupBox_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AddCopyForm)
    {
        if (AddCopyForm->objectName().isEmpty())
            AddCopyForm->setObjectName(QStringLiteral("AddCopyForm"));
        AddCopyForm->resize(383, 418);
        groupBox = new QGroupBox(AddCopyForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 361, 121));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 91, 21));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        cidF = new QLineEdit(groupBox);
        cidF->setObjectName(QStringLiteral("cidF"));
        cidF->setGeometry(QRect(160, 20, 191, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 101, 21));
        label_2->setFont(font);
        copiesCBB = new QComboBox(groupBox);
        copiesCBB->setObjectName(QStringLiteral("copiesCBB"));
        copiesCBB->setGeometry(QRect(160, 80, 191, 31));
        copiesCBB->setFont(font);
        cidErr = new QLabel(groupBox);
        cidErr->setObjectName(QStringLiteral("cidErr"));
        cidErr->setGeometry(QRect(160, 60, 191, 16));
        groupBox_2 = new QGroupBox(AddCopyForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(170, 350, 211, 51));
        okBtn = new QPushButton(groupBox_2);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(10, 10, 91, 31));
        cancelBtn = new QPushButton(groupBox_2);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(110, 10, 91, 31));

        retranslateUi(AddCopyForm);

        QMetaObject::connectSlotsByName(AddCopyForm);
    } // setupUi

    void retranslateUi(QDialog *AddCopyForm)
    {
        AddCopyForm->setWindowTitle(QApplication::translate("AddCopyForm", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("AddCopyForm", "General Information", 0));
        label->setText(QApplication::translate("AddCopyForm", "Collection ID", 0));
        label_2->setText(QApplication::translate("AddCopyForm", "Status", 0));
        cidErr->setText(QString());
        groupBox_2->setTitle(QString());
        okBtn->setText(QApplication::translate("AddCopyForm", "OK", 0));
        cancelBtn->setText(QApplication::translate("AddCopyForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCopyForm: public Ui_AddCopyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOPYFORM_H
