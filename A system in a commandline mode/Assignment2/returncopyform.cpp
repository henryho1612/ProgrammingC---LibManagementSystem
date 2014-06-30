#include "returncopyform.h"
#include "ui_returncopyform.h"
#include <sstream>
#include <string>
#include <ctime>
#include <QMessageBox>

ReturnCopyForm::ReturnCopyForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReturnCopyForm)
{
    ui->setupUi(this);

    ui->tableWidget->hide();
}

ReturnCopyForm::~ReturnCopyForm()
{
    delete ui;
}

//Get data model from main
void ReturnCopyForm::setDb(list<MultimediaCollection> &cols,
                          list<CopyCollection> &copies,
                          list<Borrower> &borrowers, DatabaseHandler *db)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
    this->dbHandler = db;
}

void ReturnCopyForm::on_barcodeF_editingFinished()
{
    QString barcode = ui->barcodeF->text();
    if(checkBarcodeExist(barcode))
    {
        ui->tableWidget->setColumnCount(6); //Set num columns of table - 6
        ui->tableWidget->setRowCount(1); //Set num rows of table

        CopyCollection tempCol = findCopyCollection(barcode);
        if(tempCol.getStatus() != "Borrowed")
        {
            ui->barcodeErr->setText("This copy was not borrowed!@@");
        }
        else {
            ui->tableWidget->clear();
            ui->tableWidget->show();
            list<CopyCollection>::iterator it = copies->begin();
            while(it != copies->end())
            {
                if(it->getBarcode() == barcode)
                {
                    if(calNumDays(it->getDateBorrowed()) > it->getNumDayBorrowed())
                    {
                        ui->barcodeErr->setText("This copy overdues");
                    }
                    else
                    {
                        ui->barcodeErr->setText("");
                    }

                        //ui->tableWidget->clear();
                        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(it->getBarcode()));

                        list<MultimediaCollection>::iterator subIt = cols->begin();
                        while(subIt != cols->end())
                        {
                            if(subIt->getCid() == it->getCid())
                            {
                                ui->tableWidget->setItem(0, 1, new QTableWidgetItem(subIt->getTitle()));
                                ui->tableWidget->setItem(0, 2, new QTableWidgetItem(subIt->getPublisher()));
                            }

                            *subIt++;
                        }
                        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(it->getDateBorrowed()));
                        ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::number(it->getNumDayBorrowed())));
                        int numDays = calNumDays(it->getDateBorrowed()) - it->getNumDayBorrowed();
                        ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(numDays)));
                    //}
                }

                *it++;
            }

            //Build table header
            ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Barcode"));
            ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Title"));
            ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Publisher"));
            ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Date Borrowed"));
            ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Num Days"));
            ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Days Late"));
        }
    }
    else {
        ui->barcodeErr->setText("Barcode is not exist!");
    }
}

void ReturnCopyForm::on_okBtn_clicked()
{
    QString barcode = ui->barcodeF->text();
    if(!checkBarcodeExist(barcode))
    {
        ui->barcodeErr->setText("Barcode is not exist!");
        ui->barcodeF->setFocus();
    }
    else
    {
        QString borrowerId = ui->borrowerF->text();
        if(!checkBidExist(borrowerId))
        {
            ui->borrowerErr->setText("Borrower id not exist!");
            ui->borrowerF->setFocus();
        }
        else
        {
            ui->borrowerErr->setText("");
            list<Borrower>::iterator it = borrowers->begin();
            while(it != borrowers->end())
            {
                if(it->getBorrowerId() ==  borrowerId)
                {
                    QString cid;
                    int isLate = 1;
                    Borrower dbBorrower;
                    CopyCollection dbCopyCollection;
                    History dbHistory;
                    list<CopyCollection>::iterator subIt = copies->begin();
                    while(subIt != copies->end())
                    {
                        if(subIt->getBarcode() == barcode)
                        {
                            cid = subIt->getCid();
                            //Late return
                            if(calNumDays(subIt->getDateBorrowed()) > subIt->getNumDayBorrowed())
                            {
                                isLate = 0;
                                it->setNoReturnedLate(it->getNoReturnedLate() + 1);

                            }

                            dbBorrower = *it;

                            //Dealing with histories of a borrower
                            list<History> histories = it->getHistories();
                            list<History>::iterator it1 = histories.begin();
                            while (it1 != histories.end())
                            {
                                if (it1->getBarcode() == barcode && it1->isReturned() == 1)
                                {
                                    it1->setLate(isLate);
                                    it1->setReturned(0);
                                    dbHistory = *it1;
                                    break;
                                }
                                *it1++;
                            }
                            it->setHistories(histories);

                            //Change status of the copy in copies
                            subIt->setStatus("In Library");
                            dbCopyCollection = *subIt;

                            //Change status of the copy in its collection
                            list<MultimediaCollection>::iterator itCols = cols->begin();
                            while(itCols != cols->end())
                            {
                                if(itCols->getCid() == cid)
                                {
                                    list<CopyCollection> cCols = itCols->getCopyCollections();

                                    list<CopyCollection>::iterator cCit = cCols.begin();
                                    while(cCit != cCols.end())
                                    {
                                        if(cCit->getBarcode() == barcode)
                                        {
                                            cCit->setStatus("In Library");
                                            cCit->setDateBorrowed("");
                                            cCit->setNumDayBorrowed(0);
                                            break;
                                        }
                                        *cCit++;
                                    }
                                    itCols->setCopyCollections(cCols);
                                    break;
                                }
                                *itCols++;
                            }
                            break;
                        }
                        *subIt++;
                    }

                    dbHandler->updateWhenReturn(&dbBorrower, &dbCopyCollection, &dbHistory);
                    break;
                }
                *it++;
            }

            QMessageBox::about(0, QObject::tr("Information"),
                               "Return copy successfully!");
            this->clearFocus();
            this->close();
        }

    }
}

void ReturnCopyForm::on_cancelBtn_clicked()
{
    this->clearFocus();
    this->hide();
}

bool ReturnCopyForm::checkBarcodeExist(QString barcode)
{
    list<CopyCollection>::iterator it = copies->begin();
    while(it != copies->end())
    {
        if(it->getBarcode() == barcode)
            return true;
        *it++;
    }
    return false;
}

bool ReturnCopyForm::checkBidExist(QString bid)
{
    list<Borrower>::iterator it = borrowers->begin();
    while(it != borrowers->end())
    {
        if(it->getBorrowerId() == bid)
            return true;
        *it++;
    }

    return false;
}

//Find a copy collection by barcode
CopyCollection ReturnCopyForm::findCopyCollection(QString barcode)
{
    list<CopyCollection>::iterator it = copies->begin();
    while(it != copies->end())
    {
        if(it->getBarcode() == barcode)
            return *it;
        *it++;
    }
    //return NULL;
}

//Source code: http://answers.yahoo.com/question/index?qid=20120927094228AAagMFB
//This calculate how many date from julian date to current
int ReturnCopyForm::julianDays(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    if (year > 1582 || (year == 1582 && month > 10) || (year == 1582 && month == 10 && day >= 15))
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    else
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
}

//Calculate how may date from the date as parameter to current.
int ReturnCopyForm::calNumDays(QString date)
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    int curYear = now->tm_year + 1900;
    int curMonth = now->tm_mon+1;
    int curDay = now->tm_mday;
    int curHour = now->tm_hour;
    int curMinute = now->tm_min;

    int year, month, day, hour, minute;

    string d = date.toStdString();
    stringstream(d.substr(6,4)) >> year;
    stringstream(d.substr(0,2)) >> day;
    stringstream(d.substr(3,2)) >> month;
    stringstream(d.substr(11,2)) >> hour;
    stringstream(d.substr(13,2)) >> minute;

    int julianCur = julianDays(curYear, curMonth, curDay);
    int julianBorrowed = julianDays(year, month, day);

    int days = julianCur - julianBorrowed;
    if(curHour*60 + curMinute > hour*60 + minute)
        days++;

    return days;
}
