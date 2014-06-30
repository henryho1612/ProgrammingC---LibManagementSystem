/********************************************************************************
** Form generated from reading UI file 'addcollectionform.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOLLECTIONFORM_H
#define UI_ADDCOLLECTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddCollectionForm
{
public:
    QGroupBox *groupBox_2;
    QLabel *cid;
    QLabel *title;
    QLabel *type;
    QLabel *datatype;
    QLabel *category;
    QLabel *version;
    QLabel *publisher;
    QLabel *year;
    QLabel *duration;
    QComboBox *typeCBB;
    QComboBox *datatypeCBB;
    QGroupBox *cateGroup;
    QCheckBox *animationCB;
    QCheckBox *adventureCB;
    QCheckBox *fantasyCB;
    QCheckBox *dramaCB;
    QCheckBox *comedyCB;
    QComboBox *yearCBB;
    QLabel *cidErr;
    QLabel *titleErr;
    QLabel *versionErr;
    QLabel *publisherErr;
    QLabel *durationErr;
    QLineEdit *cidF;
    QLineEdit *titleF;
    QLineEdit *versionF;
    QLineEdit *publisherF;
    QLineEdit *durationF;
    QComboBox *numcopiesCBB;
    QLabel *year_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AddCollectionForm)
    {
        if (AddCollectionForm->objectName().isEmpty())
            AddCollectionForm->setObjectName(QStringLiteral("AddCollectionForm"));
        AddCollectionForm->resize(396, 637);
        groupBox_2 = new QGroupBox(AddCollectionForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 30, 371, 561));
        cid = new QLabel(groupBox_2);
        cid->setObjectName(QStringLiteral("cid"));
        cid->setGeometry(QRect(10, 20, 141, 31));
        QFont font;
        font.setPointSize(10);
        cid->setFont(font);
        title = new QLabel(groupBox_2);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(10, 80, 141, 31));
        title->setFont(font);
        type = new QLabel(groupBox_2);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(10, 140, 141, 31));
        type->setFont(font);
        datatype = new QLabel(groupBox_2);
        datatype->setObjectName(QStringLiteral("datatype"));
        datatype->setGeometry(QRect(10, 180, 141, 31));
        datatype->setFont(font);
        category = new QLabel(groupBox_2);
        category->setObjectName(QStringLiteral("category"));
        category->setGeometry(QRect(10, 220, 141, 31));
        category->setFont(font);
        version = new QLabel(groupBox_2);
        version->setObjectName(QStringLiteral("version"));
        version->setGeometry(QRect(10, 300, 141, 31));
        version->setFont(font);
        publisher = new QLabel(groupBox_2);
        publisher->setObjectName(QStringLiteral("publisher"));
        publisher->setGeometry(QRect(10, 360, 141, 31));
        publisher->setFont(font);
        year = new QLabel(groupBox_2);
        year->setObjectName(QStringLiteral("year"));
        year->setGeometry(QRect(10, 420, 141, 31));
        year->setFont(font);
        duration = new QLabel(groupBox_2);
        duration->setObjectName(QStringLiteral("duration"));
        duration->setGeometry(QRect(10, 460, 141, 31));
        duration->setFont(font);
        typeCBB = new QComboBox(groupBox_2);
        typeCBB->setObjectName(QStringLiteral("typeCBB"));
        typeCBB->setGeometry(QRect(150, 140, 121, 31));
        datatypeCBB = new QComboBox(groupBox_2);
        datatypeCBB->setObjectName(QStringLiteral("datatypeCBB"));
        datatypeCBB->setGeometry(QRect(150, 180, 121, 31));
        cateGroup = new QGroupBox(groupBox_2);
        cateGroup->setObjectName(QStringLiteral("cateGroup"));
        cateGroup->setGeometry(QRect(150, 220, 201, 71));
        animationCB = new QCheckBox(cateGroup);
        animationCB->setObjectName(QStringLiteral("animationCB"));
        animationCB->setGeometry(QRect(10, 10, 81, 17));
        QFont font1;
        font1.setPointSize(9);
        animationCB->setFont(font1);
        adventureCB = new QCheckBox(cateGroup);
        adventureCB->setObjectName(QStringLiteral("adventureCB"));
        adventureCB->setGeometry(QRect(100, 10, 81, 17));
        adventureCB->setFont(font1);
        fantasyCB = new QCheckBox(cateGroup);
        fantasyCB->setObjectName(QStringLiteral("fantasyCB"));
        fantasyCB->setGeometry(QRect(10, 30, 81, 17));
        fantasyCB->setFont(font1);
        dramaCB = new QCheckBox(cateGroup);
        dramaCB->setObjectName(QStringLiteral("dramaCB"));
        dramaCB->setGeometry(QRect(10, 50, 81, 17));
        dramaCB->setFont(font1);
        comedyCB = new QCheckBox(cateGroup);
        comedyCB->setObjectName(QStringLiteral("comedyCB"));
        comedyCB->setGeometry(QRect(100, 30, 81, 17));
        comedyCB->setFont(font1);
        yearCBB = new QComboBox(groupBox_2);
        yearCBB->setObjectName(QStringLiteral("yearCBB"));
        yearCBB->setGeometry(QRect(150, 420, 121, 31));
        yearCBB->setFont(font);
        cidErr = new QLabel(groupBox_2);
        cidErr->setObjectName(QStringLiteral("cidErr"));
        cidErr->setGeometry(QRect(150, 60, 201, 16));
        titleErr = new QLabel(groupBox_2);
        titleErr->setObjectName(QStringLiteral("titleErr"));
        titleErr->setGeometry(QRect(150, 120, 201, 16));
        versionErr = new QLabel(groupBox_2);
        versionErr->setObjectName(QStringLiteral("versionErr"));
        versionErr->setGeometry(QRect(150, 340, 201, 16));
        publisherErr = new QLabel(groupBox_2);
        publisherErr->setObjectName(QStringLiteral("publisherErr"));
        publisherErr->setGeometry(QRect(150, 400, 201, 16));
        durationErr = new QLabel(groupBox_2);
        durationErr->setObjectName(QStringLiteral("durationErr"));
        durationErr->setGeometry(QRect(150, 500, 201, 16));
        cidF = new QLineEdit(groupBox_2);
        cidF->setObjectName(QStringLiteral("cidF"));
        cidF->setGeometry(QRect(150, 19, 201, 31));
        cidF->setFont(font);
        titleF = new QLineEdit(groupBox_2);
        titleF->setObjectName(QStringLiteral("titleF"));
        titleF->setGeometry(QRect(150, 80, 201, 31));
        titleF->setFont(font);
        versionF = new QLineEdit(groupBox_2);
        versionF->setObjectName(QStringLiteral("versionF"));
        versionF->setGeometry(QRect(150, 300, 201, 31));
        versionF->setFont(font);
        publisherF = new QLineEdit(groupBox_2);
        publisherF->setObjectName(QStringLiteral("publisherF"));
        publisherF->setGeometry(QRect(150, 360, 201, 31));
        publisherF->setFont(font);
        durationF = new QLineEdit(groupBox_2);
        durationF->setObjectName(QStringLiteral("durationF"));
        durationF->setGeometry(QRect(150, 460, 201, 31));
        durationF->setFont(font);
        numcopiesCBB = new QComboBox(groupBox_2);
        numcopiesCBB->setObjectName(QStringLiteral("numcopiesCBB"));
        numcopiesCBB->setGeometry(QRect(150, 520, 121, 31));
        numcopiesCBB->setFont(font);
        year_2 = new QLabel(groupBox_2);
        year_2->setObjectName(QStringLiteral("year_2"));
        year_2->setGeometry(QRect(10, 520, 141, 31));
        year_2->setFont(font);
        okBtn = new QPushButton(AddCollectionForm);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(230, 600, 75, 31));
        cancelBtn = new QPushButton(AddCollectionForm);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(310, 600, 75, 31));

        retranslateUi(AddCollectionForm);

        QMetaObject::connectSlotsByName(AddCollectionForm);
    } // setupUi

    void retranslateUi(QDialog *AddCollectionForm)
    {
        AddCollectionForm->setWindowTitle(QApplication::translate("AddCollectionForm", "Dialog", 0));
        groupBox_2->setTitle(QApplication::translate("AddCollectionForm", "Add New Collection", 0));
        cid->setText(QApplication::translate("AddCollectionForm", "Collection ID", 0));
        title->setText(QApplication::translate("AddCollectionForm", "Title", 0));
        type->setText(QApplication::translate("AddCollectionForm", "Type", 0));
        datatype->setText(QApplication::translate("AddCollectionForm", "Data Type", 0));
        category->setText(QApplication::translate("AddCollectionForm", "Category", 0));
        version->setText(QApplication::translate("AddCollectionForm", "Version", 0));
        publisher->setText(QApplication::translate("AddCollectionForm", "Publisher", 0));
        year->setText(QApplication::translate("AddCollectionForm", "Record Year", 0));
        duration->setText(QApplication::translate("AddCollectionForm", "Duration", 0));
        cateGroup->setTitle(QString());
        animationCB->setText(QApplication::translate("AddCollectionForm", "Animation", 0));
        adventureCB->setText(QApplication::translate("AddCollectionForm", "Adventure", 0));
        fantasyCB->setText(QApplication::translate("AddCollectionForm", "Fantasy", 0));
        dramaCB->setText(QApplication::translate("AddCollectionForm", "Drama", 0));
        comedyCB->setText(QApplication::translate("AddCollectionForm", "Comedy", 0));
        cidErr->setText(QString());
        titleErr->setText(QString());
        versionErr->setText(QString());
        publisherErr->setText(QString());
        durationErr->setText(QString());
        year_2->setText(QApplication::translate("AddCollectionForm", "Num Copies", 0));
        okBtn->setText(QApplication::translate("AddCollectionForm", "OK", 0));
        cancelBtn->setText(QApplication::translate("AddCollectionForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCollectionForm: public Ui_AddCollectionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOLLECTIONFORM_H
