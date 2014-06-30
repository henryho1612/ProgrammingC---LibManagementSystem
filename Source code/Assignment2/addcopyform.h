#ifndef ADDCOPYFORM_H
#define ADDCOPYFORM_H

#include "mainwindow.h"
#include "multimediacollection.h"
#include "borrower.h"
#include "copycollection.h"
#include <QDialog>
#include <QtGui>
#include "databasehandler.h"

namespace Ui {
class AddCopyForm;
}

class AddCopyForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddCopyForm(QWidget *parent = 0);
    ~AddCopyForm();

    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers,
               DatabaseHandler *db);

    bool checkCidExist(QString cid);
    MainWindow *mW;
    QString generateBarcode();

private slots:
    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

    void on_copiesCBB_currentIndexChanged(const QString &arg1);

private:
    Ui::AddCopyForm *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    list<Borrower> *borrowers;
    DatabaseHandler *dbHandler;
};

#endif // ADDCOPYFORM_H
