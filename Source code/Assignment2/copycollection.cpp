#include "copycollection.h"

#include <iostream>
#include <iomanip>

using namespace std;

CopyCollection::CopyCollection() {}
CopyCollection::CopyCollection(int id, QString cid, QString barcode, QString status, int borrowingTimes)
    : id(id), cid(cid), barcode(barcode), status(status), borrowingTimes(borrowingTimes)
{
    numDayBorrowed = 0;
    dateBorrowed = " ";
}

CopyCollection::~CopyCollection() {}

//getters
int CopyCollection::getId()
{
    return id;
}

QString CopyCollection::getCid()
{
    return cid;
}

QString CopyCollection::getBarcode()
{
    return barcode;
}

QString CopyCollection::getStatus()
{
    return status;
}

int CopyCollection::getBorrowingTimes()
{
    return borrowingTimes;
}

int CopyCollection::getNumDayBorrowed()
{
    return numDayBorrowed;
}

QString CopyCollection::getDateBorrowed()
{
    return dateBorrowed;
}

//setters
void CopyCollection::setCid(QString cid)
{
    this->cid = cid;
}

void CopyCollection::setBarcode(QString barcode)
{
    this->barcode = barcode;
}

void CopyCollection::setStatus(QString status)
{
    this->status = status;
}

void CopyCollection::setBorrowingTimes(int borrowingTimes)
{
    this->borrowingTimes = borrowingTimes;
}

void CopyCollection::setNumDayBorrowed(int days)
{
    numDayBorrowed = days;
}

void CopyCollection::setDateBorrowed(QString date)
{
    dateBorrowed  = date;
}
