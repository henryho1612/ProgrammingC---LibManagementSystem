#ifndef RETURNCOPYFORM_H
#define RETURNCOPYFORM_H

#include "mainwindow.h"
#include "multimediacollection.h"
#include "borrower.h"
#include "copycollection.h"
#include <QDialog>
#include <QtGui>
#include "databasehandler.h"

namespace Ui {
class ReturnCopyForm;
}

class ReturnCopyForm : public QDialog
{
    Q_OBJECT

public:
    explicit ReturnCopyForm(QWidget *parent = 0);
    ~ReturnCopyForm();

    MainWindow *mW;
    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers,
               DatabaseHandler *db);

    bool checkBarcodeExist(QString barcode);
    bool checkBidExist(QString bid);
    CopyCollection findCopyCollection(QString barcode);
    int julianDays(int year, int month, int day);
    int calNumDays(QString date);

private slots:
    void on_barcodeF_editingFinished();

    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::ReturnCopyForm *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    list<Borrower> *borrowers;
    DatabaseHandler *dbHandler;
};

#endif // RETURNCOPYFORM_H
