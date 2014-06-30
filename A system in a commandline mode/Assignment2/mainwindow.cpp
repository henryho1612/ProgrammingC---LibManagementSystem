#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "showallcollections.h"
#include "showcopies.h"
#include "borrowerform.h"
#include "addcollectionform.h"
#include "addcopyform.h"
#include "borrowcopyform.h"
#include "returncopyform.h"
#include "addborrowerform.h"
#include "changestatusform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Assignment 2 - Librarian Management"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//List All Collections
void MainWindow::on_listColBtn_clicked()
{
    this->hide();
    showAllCollections showCols;
    showCols.mW = this;
    showCols.setModal(true);
    showCols.setDb(cols, copies, borrowers);
    showCols.exec();
}

//List Collections
void MainWindow::on_listCopyBtn_clicked()
{
    this->hide();
    showCopies show_Copies;
    show_Copies.mW = this;
    show_Copies.setModal(true);
    show_Copies.setDb(cols, copies, borrowers);
    show_Copies.exec();
}

//List Borrowers
void MainWindow::on_listBorrowBtn_clicked()
{
    this->hide();
    BorrowerForm bForm;
    bForm.mW = this;
    bForm.setModal(true);
    bForm.setDb(cols, copies, borrowers);
    bForm.exec();
}

//Add New Collection
void MainWindow::on_addColBtn_clicked()
{
    AddCollectionForm addColF;
    addColF.setModal(true);
    addColF.mW = this;
    addColF.setDb(cols, copies, borrowers, testDB);
    addColF.setFocus();
    addColF.exec();
}

//Add New Copy
void MainWindow::on_addCopyBtn_clicked()
{
    AddCopyForm addCopF;
    addCopF.setModal(true);
    addCopF.mW = this;
    addCopF.setDb(cols, copies, borrowers, testDB);
    addCopF.setFocus();
    addCopF.exec();
}

//Borrow a copy collection
void MainWindow::on_borrowBtn_clicked()
{
    BorrowCopyForm borrowCForm;
    borrowCForm.setModal(true);
    borrowCForm.mW = this;
    borrowCForm.setDb(cols, copies, borrowers, testDB);
    borrowCForm.setFocus();
    borrowCForm.exec();
}

//Return copy collection
void MainWindow::on_returnBtn_clicked()
{
    ReturnCopyForm returnCForm;
    returnCForm.setModal(true);
    returnCForm.mW = this;
    returnCForm.setDb(cols, copies, borrowers, testDB);
    returnCForm.setFocus();
    returnCForm.exec();
}

//Add New Borrower
void MainWindow::on_addBorrowerBtn_clicked()
{
    AddBorrowerForm addBForm;
    addBForm.setModal(true);
    addBForm.mW = this;
    addBForm.setDb(cols, copies, borrowers, testDB);
    addBForm.setFocus();
    addBForm.exec();
}

void MainWindow::on_statusBtn_clicked()
{
    ChangeStatusForm statusForm;
    statusForm.setModal(true);
    statusForm.mW = this;
    statusForm.setDb(cols, copies, borrowers);
    statusForm.setFocus();
    statusForm.exec();
}

void MainWindow::setDb(list<MultimediaCollection> &cols,
                       list<CopyCollection> &copies,
                       list<Borrower> &borrowers, DatabaseHandler *db)
{
    this->cols = cols;
    this->copies = copies;
    this->borrowers = borrowers;
    this->testDB = db;
}

list<MultimediaCollection> MainWindow::getCollections(){return cols;}
list<CopyCollection> MainWindow::getCopies(){return copies;}
list<Borrower> MainWindow::getBorrowers(){return borrowers;}

void MainWindow::setCollections(list<MultimediaCollection> cols){this->cols = cols;}
void MainWindow::setCopies(list<CopyCollection> copies) {this->copies = copies;}
void MainWindow::setBorrowers(list<Borrower> borrowers){this->borrowers = borrowers;}



void MainWindow::on_actionAdd_New_Collection_triggered()
{
    on_addColBtn_clicked();
}
