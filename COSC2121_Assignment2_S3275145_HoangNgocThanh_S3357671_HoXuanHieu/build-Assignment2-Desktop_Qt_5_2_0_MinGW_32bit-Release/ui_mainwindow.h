/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_New_Collection;
    QAction *actionAdd_New_Copy;
    QAction *actionBorrow_A_Copy;
    QAction *actionReturn_A_Copy;
    QAction *actionTheme_1;
    QAction *actionTheme_2;
    QAction *actionProject_Team;
    QAction *actionProject_Brief;
    QAction *actionShow_Collections;
    QAction *actionShow_Copies;
    QAction *actionShow_Borrowers;
    QAction *actionExit;
    QAction *actionChange_Status;
    QAction *actionAdd_New_Borrower;
    QWidget *centralWidget;
    QGroupBox *DataEntry;
    QPushButton *addColBtn;
    QPushButton *addCopyBtn;
    QPushButton *addBorrowerBtn;
    QGroupBox *operation;
    QPushButton *borrowBtn;
    QPushButton *returnBtn;
    QPushButton *statusBtn;
    QGroupBox *Report;
    QPushButton *listColBtn;
    QPushButton *listCopyBtn;
    QPushButton *listBorrowBtn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuAbout;
    QMenu *menuHelp;
    QMenu *menuHelp_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(571, 352);
        actionAdd_New_Collection = new QAction(MainWindow);
        actionAdd_New_Collection->setObjectName(QStringLiteral("actionAdd_New_Collection"));
        actionAdd_New_Copy = new QAction(MainWindow);
        actionAdd_New_Copy->setObjectName(QStringLiteral("actionAdd_New_Copy"));
        actionBorrow_A_Copy = new QAction(MainWindow);
        actionBorrow_A_Copy->setObjectName(QStringLiteral("actionBorrow_A_Copy"));
        actionReturn_A_Copy = new QAction(MainWindow);
        actionReturn_A_Copy->setObjectName(QStringLiteral("actionReturn_A_Copy"));
        actionTheme_1 = new QAction(MainWindow);
        actionTheme_1->setObjectName(QStringLiteral("actionTheme_1"));
        actionTheme_2 = new QAction(MainWindow);
        actionTheme_2->setObjectName(QStringLiteral("actionTheme_2"));
        actionProject_Team = new QAction(MainWindow);
        actionProject_Team->setObjectName(QStringLiteral("actionProject_Team"));
        actionProject_Brief = new QAction(MainWindow);
        actionProject_Brief->setObjectName(QStringLiteral("actionProject_Brief"));
        actionShow_Collections = new QAction(MainWindow);
        actionShow_Collections->setObjectName(QStringLiteral("actionShow_Collections"));
        actionShow_Copies = new QAction(MainWindow);
        actionShow_Copies->setObjectName(QStringLiteral("actionShow_Copies"));
        actionShow_Borrowers = new QAction(MainWindow);
        actionShow_Borrowers->setObjectName(QStringLiteral("actionShow_Borrowers"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionChange_Status = new QAction(MainWindow);
        actionChange_Status->setObjectName(QStringLiteral("actionChange_Status"));
        actionAdd_New_Borrower = new QAction(MainWindow);
        actionAdd_New_Borrower->setObjectName(QStringLiteral("actionAdd_New_Borrower"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DataEntry = new QGroupBox(centralWidget);
        DataEntry->setObjectName(QStringLiteral("DataEntry"));
        DataEntry->setGeometry(QRect(10, 50, 371, 61));
        addColBtn = new QPushButton(DataEntry);
        addColBtn->setObjectName(QStringLiteral("addColBtn"));
        addColBtn->setGeometry(QRect(10, 20, 101, 31));
        addCopyBtn = new QPushButton(DataEntry);
        addCopyBtn->setObjectName(QStringLiteral("addCopyBtn"));
        addCopyBtn->setGeometry(QRect(120, 20, 111, 31));
        addBorrowerBtn = new QPushButton(DataEntry);
        addBorrowerBtn->setObjectName(QStringLiteral("addBorrowerBtn"));
        addBorrowerBtn->setGeometry(QRect(240, 20, 111, 31));
        operation = new QGroupBox(centralWidget);
        operation->setObjectName(QStringLiteral("operation"));
        operation->setGeometry(QRect(10, 120, 371, 61));
        borrowBtn = new QPushButton(operation);
        borrowBtn->setObjectName(QStringLiteral("borrowBtn"));
        borrowBtn->setGeometry(QRect(10, 20, 101, 31));
        returnBtn = new QPushButton(operation);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));
        returnBtn->setGeometry(QRect(120, 20, 111, 31));
        statusBtn = new QPushButton(operation);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));
        statusBtn->setGeometry(QRect(240, 20, 111, 31));
        Report = new QGroupBox(centralWidget);
        Report->setObjectName(QStringLiteral("Report"));
        Report->setGeometry(QRect(10, 200, 241, 101));
        listColBtn = new QPushButton(Report);
        listColBtn->setObjectName(QStringLiteral("listColBtn"));
        listColBtn->setGeometry(QRect(10, 20, 101, 31));
        listCopyBtn = new QPushButton(Report);
        listCopyBtn->setObjectName(QStringLiteral("listCopyBtn"));
        listCopyBtn->setGeometry(QRect(120, 20, 111, 31));
        listBorrowBtn = new QPushButton(Report);
        listBorrowBtn->setObjectName(QStringLiteral("listBorrowBtn"));
        listBorrowBtn->setGeometry(QRect(10, 60, 221, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 571, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp_2 = new QMenu(menuBar);
        menuHelp_2->setObjectName(QStringLiteral("menuHelp_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuHelp_2->menuAction());
        menuFile->addAction(actionAdd_New_Collection);
        menuFile->addAction(actionAdd_New_Copy);
        menuFile->addAction(actionAdd_New_Borrower);
        menuFile->addAction(actionBorrow_A_Copy);
        menuFile->addAction(actionReturn_A_Copy);
        menuFile->addAction(actionChange_Status);
        menuFile->addAction(actionExit);
        menuView->addAction(actionTheme_1);
        menuView->addAction(actionTheme_2);
        menuAbout->addAction(actionProject_Team);
        menuAbout->addAction(actionProject_Brief);
        menuHelp->addAction(actionShow_Collections);
        menuHelp->addAction(actionShow_Copies);
        menuHelp->addAction(actionShow_Borrowers);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd_New_Collection->setText(QApplication::translate("MainWindow", "Add New Collection", 0));
        actionAdd_New_Copy->setText(QApplication::translate("MainWindow", "Add New Copy", 0));
        actionBorrow_A_Copy->setText(QApplication::translate("MainWindow", "Borrow A Copy", 0));
        actionReturn_A_Copy->setText(QApplication::translate("MainWindow", "Return A Copy", 0));
        actionTheme_1->setText(QApplication::translate("MainWindow", "Theme 1", 0));
        actionTheme_2->setText(QApplication::translate("MainWindow", "Theme 2", 0));
        actionProject_Team->setText(QApplication::translate("MainWindow", "Project Team", 0));
        actionProject_Brief->setText(QApplication::translate("MainWindow", "Project Brief", 0));
        actionShow_Collections->setText(QApplication::translate("MainWindow", "Show Collections", 0));
        actionShow_Copies->setText(QApplication::translate("MainWindow", "Show Copies", 0));
        actionShow_Borrowers->setText(QApplication::translate("MainWindow", "Show Borrowers", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionChange_Status->setText(QApplication::translate("MainWindow", "Change Status", 0));
        actionAdd_New_Borrower->setText(QApplication::translate("MainWindow", "Add New Borrower", 0));
        DataEntry->setTitle(QApplication::translate("MainWindow", "Data Entry", 0));
        addColBtn->setText(QApplication::translate("MainWindow", "Add New Collection", 0));
        addCopyBtn->setText(QApplication::translate("MainWindow", "Add New Copy", 0));
        addBorrowerBtn->setText(QApplication::translate("MainWindow", "Add Borrower", 0));
        operation->setTitle(QApplication::translate("MainWindow", "Daily Operation", 0));
        borrowBtn->setText(QApplication::translate("MainWindow", "Borrow Copy", 0));
        returnBtn->setText(QApplication::translate("MainWindow", "Return Copy", 0));
        statusBtn->setText(QApplication::translate("MainWindow", "Change Status", 0));
        Report->setTitle(QApplication::translate("MainWindow", "Report", 0));
        listColBtn->setText(QApplication::translate("MainWindow", "All Collections", 0));
        listCopyBtn->setText(QApplication::translate("MainWindow", "All Copies", 0));
        listBorrowBtn->setText(QApplication::translate("MainWindow", "All Borrowers And Overdue", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "Theme", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Report", 0));
        menuHelp_2->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
