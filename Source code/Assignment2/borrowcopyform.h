#ifndef BORROWCOPYFORM_H
#define BORROWCOPYFORM_H

#include "mainwindow.h"
#include "multimediacollection.h"
#include "borrower.h"
#include "copycollection.h"
#include <QDialog>
#include <QtGui>
#include "databasehandler.h"
namespace Ui {
class BorrowCopyForm;
}

class BorrowCopyForm : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowCopyForm(QWidget *parent = 0);
    ~BorrowCopyForm();

    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers,
               DatabaseHandler *db);

    bool checkBarcodeExist(QString barcode);
    bool checkBidExist(QString bid);
    MainWindow *mW;
    MultimediaCollection findCollection(QString cid);
    CopyCollection findCopyCollection(QString barcode);
    QString getCurDate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_bidF_editingFinished();

private:
    Ui::BorrowCopyForm *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    list<Borrower> *borrowers;
    DatabaseHandler *dbHandler;
};

#endif // BORROWCOPYFORM_H
