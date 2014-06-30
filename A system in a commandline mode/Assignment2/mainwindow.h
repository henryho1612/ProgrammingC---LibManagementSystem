#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "borrower.h"
#include "copycollection.h"
#include <QMainWindow>
#include "databasehandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers, DatabaseHandler *db);


    list<MultimediaCollection> getCollections();
    list<CopyCollection> getCopies();
    list<Borrower> getBorrowers();

    void setCollections(list<MultimediaCollection> cols);
    void setCopies(list<CopyCollection> copies);
    void setBorrowers(list<Borrower> borrowers);

private slots:
    void on_listColBtn_clicked();

    void on_listCopyBtn_clicked();

    void on_listBorrowBtn_clicked();

    void on_addColBtn_clicked();

    void on_addCopyBtn_clicked();

    void on_borrowBtn_clicked();

    void on_returnBtn_clicked();

    void on_addBorrowerBtn_clicked();

    void on_statusBtn_clicked();

    void on_actionAdd_New_Collection_triggered();

private:
    Ui::MainWindow *ui;

    list<MultimediaCollection> cols;
    list<CopyCollection> copies;
    list<Borrower> borrowers;
    DatabaseHandler *testDB;

};

#endif // MAINWINDOW_H
