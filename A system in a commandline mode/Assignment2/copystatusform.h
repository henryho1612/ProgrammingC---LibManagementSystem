#ifndef COPYSTATUSFORM_H
#define COPYSTATUSFORM_H
#include <QList>
#include <QComboBox>
#include <QDialog>
#include "addcollectionform.h"
#include "databasehandler.h"

namespace Ui {
class CopyStatusForm;
}

class CopyStatusForm : public QDialog
{
    Q_OBJECT

public:
    explicit CopyStatusForm(QWidget *parent = 0);
    ~CopyStatusForm();
    AddCollectionForm *aCF;
    DatabaseHandler *dbHandler;
    MultimediaCollection mC;
    QList<QComboBox*> listCBB;
    QList<QString> listBarcode;

    void setDb(list<MultimediaCollection> *cols,
               list<CopyCollection> *copies,
               int numCopies,
               MultimediaCollection mC);
    QString generateBarcode();

    void buildUI();

private slots:
    void on_okBtn_clicked();

private:
    Ui::CopyStatusForm *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    int numCopies;

};

#endif // COPYSTATUSFORM_H
