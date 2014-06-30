#include "copystatusform.h"
#include "ui_copystatusform.h"
#include <list>
#include <QComboBox>
#include <QListWidget>
#include <QLabel>
#include <sstream>
#include <ctime>
#include <QMessageBox>

CopyStatusForm::CopyStatusForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CopyStatusForm)
{
    ui->setupUi(this);

}

CopyStatusForm::~CopyStatusForm()
{
    delete ui;
}

void CopyStatusForm::setDb(list<MultimediaCollection> *cols, list<CopyCollection> *copies,
                           int numCopies, MultimediaCollection mC)
{
    this->cols = cols;
    this->copies = copies;
    this->numCopies = numCopies;
    this->mC = mC;
}

void CopyStatusForm::buildUI()
{
    QList<QString> items;
    items.append("In Library");
    items.append("In Storeroom");

    for(int i=0; i< numCopies; i++)
    {
        QString barcode = mC.getCid() + generateBarcode() + QString::number(i);
        QLabel *label = new QLabel(barcode);
        label->setMinimumHeight(20);
        label->setMinimumWidth(70);

        QComboBox *temp = new QComboBox;
        temp->addItems(items);
        temp->setMinimumHeight(20);
        temp->setMinimumWidth(50);

        ui->gridLayout->addWidget(label);
        ui->gridLayout->addWidget(temp);

        listCBB.push_back(temp);
        listBarcode.push_back(barcode);
    }
    QFrame *myFrame = new QFrame;
    myFrame->setLayout(ui->gridLayout);
    ui->scrollArea->setWidget(myFrame);
}

QString CopyStatusForm::generateBarcode()
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

void CopyStatusForm::on_okBtn_clicked()
{
    list<CopyCollection> tempCopy = mC.getCopyCollections();
    QList<QComboBox*>::iterator iter1 =  listCBB.begin();
    QList<QString>::iterator  iter2 = listBarcode.begin();
    while (iter1 != listCBB.end() && iter2 != listBarcode.end())
    {
        CopyCollection copy;
        copy.setCid(mC.getCid());
        copy.setBarcode(*iter2);
        copy.setBorrowingTimes(0);
        copy.setStatus((*iter1)->currentText());

        qDebug() << mC.getCid() << "|" << *iter2 << "|" << (*iter1)->currentText();
        //Database
        dbHandler->insertCopyCollection(&copy);

        //Client side
        copies->push_back(copy);

        tempCopy.push_back(copy);

        *iter1++;
        *iter2++;
    }
    mC.setCopyCollections(tempCopy);
    cols->push_back(mC);
    
    dbHandler->insertMultiCollection(&mC);

    dbHandler->insertMultiCate(mC.getCategories());

    QMessageBox::about(0, QObject::tr("Information"),
                       "Add New Collection Successfully!");
    this->clearFocus();
    this->close();
}
