#ifndef ADDCOLLECTIONFORM_H
#define ADDCOLLECTIONFORM_H

#include "mainwindow.h"
#include "multimediacollection.h"
#include "borrower.h"
#include "copycollection.h"
#include <QDialog>
#include <QtGui>

namespace Ui {
class AddCollectionForm;
}

class AddCollectionForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddCollectionForm(QWidget *parent = 0);
    ~AddCollectionForm();
    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers,
               DatabaseHandler *db);

    bool checkCidExist(QString cid);
    MainWindow *mW;


private slots:
    void on_okBtn_clicked();
    void on_cancelBtn_clicked();

private:
    Ui::AddCollectionForm *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    list<Borrower> *borrowers;
    DatabaseHandler *dbHandler;
};

#endif // ADDCOLLECTIONFORM_H
