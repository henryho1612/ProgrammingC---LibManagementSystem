#ifndef SHOWCOPIES_H
#define SHOWCOPIES_H

#include "mainwindow.h"
#include "multimediacollection.h"
#include "borrower.h"
#include "copycollection.h"
#include <QDialog>
#include <QtGui>
#include <QDialog>
#include <QtGui>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPrintDialog>

namespace Ui {
class showCopies;
}

class showCopies : public QDialog
{
    Q_OBJECT

public:
    explicit showCopies(QWidget *parent = 0);
    ~showCopies();
    MainWindow *mW;

    void setDb(list<MultimediaCollection> &cols,
               list<CopyCollection> &copies,
               list<Borrower> &borrowers);
    int julianDays(int year, int month, int day);
    int calNumDays(QString date);

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *key);

    void on_previewBtn_clicked();

    void on_printBtn_clicked();

    void print(QPrinter*);

private:
    Ui::showCopies *ui;

    list<MultimediaCollection> *cols;
    list<CopyCollection> *copies;
    list<Borrower> *borrowers;
};

#endif // SHOWCOPIES_H
