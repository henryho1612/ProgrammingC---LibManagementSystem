#ifndef SHOWALLCOLLECTIONS_H
#define SHOWALLCOLLECTIONS_H

#include "mainwindow.h"
#include "multimediacollection.h"
#include "borrower.h"
#include "copycollection.h"
#include <QDialog>
#include <QtGui>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPrintDialog>

namespace Ui {
class showAllCollections;
}

class showAllCollections : public QDialog
{
    Q_OBJECT

public:
    explicit showAllCollections(QWidget *parent = 0);
    ~showAllCollections();
    MainWindow *mW;
    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *key);

    void on_printpreviewBnt_clicked();

    void on_printBtn_clicked();

    void print(QPrinter*);

private:
    Ui::showAllCollections *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    list<Borrower> *borrowers;
};

#endif // SHOWALLCOLLECTIONS_H
