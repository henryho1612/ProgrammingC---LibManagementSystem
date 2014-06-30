#ifndef ADDBORROWERFORM_H
#define ADDBORROWERFORM_H

#include "mainwindow.h"
#include "multimediacollection.h"
#include "borrower.h"
#include "copycollection.h"
#include <QDialog>
#include <QtGui>
#include "databasehandler.h"
#include <QtSql>

namespace Ui {
class AddBorrowerForm;
}

class AddBorrowerForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddBorrowerForm(QWidget *parent = 0);
    ~AddBorrowerForm();
    MainWindow *mW;


    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers, DatabaseHandler *db);
    bool checkBidExist(QString bid);
    bool checkValidBid(QString bid);

private slots:
    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::AddBorrowerForm *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    list<Borrower> *borrowers;
    DatabaseHandler *dbHandler;
};

#endif // ADDBORROWERFORM_H
