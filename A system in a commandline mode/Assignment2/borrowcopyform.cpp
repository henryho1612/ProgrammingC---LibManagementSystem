#include "borrowcopyform.h"
#include "ui_borrowcopyform.h"
#include <list>
#include <sstream>
#include <string>
#include <ctime>
#include <QMessageBox>

BorrowCopyForm::BorrowCopyForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowCopyForm)
{
    ui->setupUi(this);

    QList<QString> days;
    for(int i=1; i<10; i++)
        days.append(QString::number(i));
    ui->comboBox->addItems(days);

    ui->tableWidget->hide();
}

BorrowCopyForm::~BorrowCopyForm()
{
    delete ui;
}

//Get data model from main
void BorrowCopyForm::setDb(list<MultimediaCollection> &cols,
                          list<CopyCollection> &copies,
                          list<Borrower> &borrowers,
                          DatabaseHandler *db)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
    this->dbHandler = db;
}

void BorrowCopyForm::on_pushButton_clicked()
{
    QString borrowerId = ui->bidF->text();
    if(!checkBidExist(borrowerId))
    {
        ui->bidErr->setText("Borrower id not exist!");
        ui->bidF->setFocus();
    } else {
        ui->bidErr->setText("");
        QString barcode = ui->barcodeF->text();
        if(!checkBarcodeExist(barcode))
        {
            ui->barcodeErr->setText("Barcode is not exist!");
            ui->barcodeF->setFocus();
        } else {
            ui->barcodeErr->setText("");
            CopyCollection tempCopy = findCopyCollection(barcode);
            if(tempCopy.getStatus() == "Borrowed" || tempCopy.getStatus() == "Lost" || tempCopy.getStatus() == "In Storeroom")
            {
                ui->barcodeErr->setText("Out of service!");
                ui->barcodeF->setFocus();
            } else {
                ui->barcodeErr->setText("");

                QString cid;
                Borrower dbBorrower;
                CopyCollection dbCopyCollection;
                History dbHistory;

                //Change status of copy in copies
                list<CopyCollection>::iterator it1 = copies->begin();
                while(it1 != copies->end())
                {
                    if(it1->getBarcode() == barcode)
                    {
                        it1->setBorrowingTimes(it1->getBorrowingTimes()+1);
                        it1->setStatus("Borrowed");
                        it1->setDateBorrowed(getCurDate());
                        it1->setNumDayBorrowed(ui->comboBox->currentText().toInt());
                        cid = it1->getCid();

                        dbCopyCollection = *it1;
                        break;
                    }
                    *it1++;
                }

                list<MultimediaCollection>::iterator it = cols->begin();
                while (it != cols->end())
                {
                    if (it->getCid() == cid)
                    {
                        list<CopyCollection> tempCopy = it->getCopyCollections();
                        list<CopyCollection>::iterator it01 = tempCopy.begin();
                        while (it01 != tempCopy.end())
                        {
                            if (it01->getBarcode() == barcode)
                            {
                                it01->setBorrowingTimes(it01->getBorrowingTimes() + 1);
                                it01->setStatus("Borrowed");
                                it01->setDateBorrowed(getCurDate());
                                it1->setNumDayBorrowed(ui->comboBox->currentText().toInt());
                                break;
                            }
                            *it01++;
                        }
                        it->setCopyCollections(tempCopy);
                        break;
                    }
                    *it++;
                }

                list<Borrower>::iterator it2 = borrowers->begin();
                while(it2 != borrowers->end())
                {
                    if(it2->getBorrowerId() == borrowerId)
                    {
                        it2->setNoBorrowed(it2->getNoBorrowed()+1);

                        list<History> tempHis = it2->getHistories();
                        History history(borrowerId, barcode, getCurDate(),
                                        ui->comboBox->currentText().toInt(),1,1);
                        tempHis.push_back(history);
                        it2->setHistories(tempHis);

                        dbBorrower = *it2;
                        dbHistory = history;
                        break;
                    }
                    *it2++;
                }

                dbHandler->updateWhenBorrow(&dbBorrower, &dbCopyCollection, &dbHistory);

                QMessageBox::about(0, QObject::tr("Information"),
                                   "Borrow copy successfully!");
                this->clearFocus();
                this->close();
            }
        }
    }
}

void BorrowCopyForm::on_pushButton_2_clicked()
{
    this->clearFocus();
    this->hide();
}

bool BorrowCopyForm::checkBidExist(QString bid)
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

bool BorrowCopyForm::checkBarcodeExist(QString barcode)
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

void BorrowCopyForm::on_bidF_editingFinished()
{
    QString borrowerId = ui->bidF->text();
    if(checkBidExist(borrowerId))
    {
        ui->tableWidget->clear();
        ui->tableWidget->show();

        ui->tableWidget->setColumnCount(6); //Set num columns of table - 6
        ui->tableWidget->setRowCount(1); //Set num rows of table
        list<Borrower>::iterator it = borrowers->begin();

        //Display data
        while(it != borrowers->end())
        {
            if(it->getBorrowerId() == borrowerId)
            {
                ui->tableWidget->setItem(0, 0, new QTableWidgetItem(it->getBorrowerId()));
                ui->tableWidget->setItem(0, 1, new QTableWidgetItem(it->getName()));
                ui->tableWidget->setItem(0, 2, new QTableWidgetItem(it->getMobile()));
                ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(it->getNoReturnedLate())));

                //Calculate num copies borrow in the past and current
                int passBorrow = 0;
                int curBorrow = 0;

                list<History> histories = it->getHistories();
                list<History>::iterator subIt = histories.begin();
                while(subIt != histories.end())
                {
                    if(subIt->isReturned() == 0)
                        passBorrow++;
                    else
                        curBorrow++;

                    *subIt++;
                }

                ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::number(passBorrow)));
                ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(curBorrow)));
            }
            *it++;
        }

        //Build table header
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Borrower ID"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Full Name"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Mobile"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("No Return Late"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Pass Borrow"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Cur Borrow"));
    }
    else
    {
        ui->bidErr->setText("Borrower id not exist!");
        ui->tableWidget->clear();
        ui->tableWidget->hide();
    }
}

//Find a collection by its id
MultimediaCollection BorrowCopyForm::findCollection(QString id)
{
    list<MultimediaCollection>::iterator it = cols->begin();
    while(it != cols->end())
    {
        if(it->getCid() == id)
            return *it;
        *it++;
    }

    //return NULL;
}

//Find a copy collection by barcode
CopyCollection BorrowCopyForm::findCopyCollection(QString barcode)
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

QString BorrowCopyForm::getCurDate()
{
    time_t t = time(0);
    stringstream ss;
    struct tm * now = localtime( & t );

    int intYear = now->tm_year + 1900;
    int intMonth = now->tm_mon+1;
    int intDay = now->tm_mday;
    int intHour = now->tm_hour;
    int intMinute = now->tm_min;
    //int intSec = now->tm_sec;

    ss << intDay << "-" << intMonth << "-" << intYear << "-" << intHour << "-" << intMinute;
    string date = ss.str();

    if (intDay < 10)
        date.insert(0,"0");
    if (intMonth < 10)
        date.insert(3,"0");
    if (intHour < 10)
        date.insert(11,"0");
    if (intMinute < 10)
        date.insert(14,"0");

    QString qstr = QString::fromStdString(date);

    return qstr;
}
