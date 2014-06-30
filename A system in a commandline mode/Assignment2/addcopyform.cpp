#include "addcopyform.h"
#include "ui_addcopyform.h"
#include <sstream>
#include <ctime>
#include <QMessageBox>

AddCopyForm::AddCopyForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCopyForm)
{
    ui->setupUi(this);

    QList<QString> status;
    status.append("In Library");
    status.append("In Storeroom");
    ui->copiesCBB->addItems(status);
}

AddCopyForm::~AddCopyForm()
{
    delete ui;
}

//Get data model from main
void AddCopyForm::setDb(list<MultimediaCollection> &cols,
                        list<CopyCollection> &copies,
                        list<Borrower> &borrowers,
                        DatabaseHandler *dbHandler)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
    this->dbHandler = dbHandler;
}

bool AddCopyForm::checkCidExist(QString cid)
{
    list<MultimediaCollection>::iterator it = cols->begin();
    while(it != cols->end())
    {
        if(it->getCid() == cid)
            return true;

        *it++;
    }

    return false;
}


void AddCopyForm::on_okBtn_clicked()
{
    QRegExp cidRegex ("[A-Z]+[0-9]{4,}");
    QString cid = ui->cidF->text();
    if(!cidRegex.exactMatch(cid))
    {
        ui->cidErr->setText("Wrong Format! Example A0001");
        ui->cidF->setFocus();
    }
    else {
        if(!checkCidExist(cid))
        {
            ui->cidErr->setText("Collection Id does not exist!");
            ui->cidF->setFocus();
        }
        else {
            ui->cidErr->setText("");

            QString copyStatus = ui->copiesCBB->currentText();
            QString barcode = cid + generateBarcode()+ QString::number(0);
            CopyCollection cC(copies->size()+1, cid, barcode, copyStatus, 0);

            list<MultimediaCollection>::iterator it = cols->begin();
            while(it != cols->end())
            {
                if(it->getCid() == cid)
                {
                    list<CopyCollection> temp = it->getCopyCollections();
                    temp.push_back(cC);
                    it->setCopyCollections(temp);
                    qDebug() << barcode;
                    break;
                }
                *it++;
            }
            copies->push_back(cC);

            dbHandler->insertCopyCollection(&cC);

            QMessageBox::about(0, QObject::tr("Information"),
                               "Add Copies Successfully!");
            this->clearFocus();
            this->close();
        }
    }
}

void AddCopyForm::on_cancelBtn_clicked()
{
    this->clearFocus();
    this->hide();
}

void AddCopyForm::on_copiesCBB_currentIndexChanged(const QString &arg1)
{

}

QString AddCopyForm::generateBarcode()
{
    time_t t = time(0);
    stringstream ss;
    struct tm * now = localtime( & t );

    int intYear = now->tm_year + 1900;
    int intMonth = now->tm_mon+1;
    int intDay = now->tm_mday;
    int intHour = now->tm_hour;
    int intMinute = now->tm_min;
    int intSec = now->tm_sec;

    ss << intDay << intMonth << intYear << intHour << intMinute << intSec;

    QString qstr = QString::fromStdString(ss.str());

    return qstr;
}
