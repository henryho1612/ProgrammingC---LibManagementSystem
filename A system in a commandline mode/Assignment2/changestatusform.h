#ifndef CHANGESTATUSFORM_H
#define CHANGESTATUSFORM_H

#include "mainwindow.h"
#include "multimediacollection.h"
#include "borrower.h"
#include "copycollection.h"
#include <QDialog>
#include <QtGui>
#include <QComboBox>

namespace Ui {
class ChangeStatusForm;
}

class ChangeStatusForm : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeStatusForm(QWidget *parent = 0);
    ~ChangeStatusForm();
    MainWindow *mW;
    QList<QComboBox*> listCBB;
    QList<QString> items;

    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers);
    bool checkBidExist(QString bid);
    bool checkValidBid(QString bid);

private slots:
    void on_searchBtn_clicked();

private:
    Ui::ChangeStatusForm *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    list<Borrower> *borrowers;
};

#endif // CHANGESTATUSFORM_H
