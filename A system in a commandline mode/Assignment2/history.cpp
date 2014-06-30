#include "history.h"

using namespace std;

History::History(int id, QString borrowerId, QString barcode, QString borrowingDate,
                 int borrowingDays, int late, int returned)
    : id(id), borrowerId(borrowerId), barcode(barcode),
      borrowingDate(borrowingDate), borrowingDays(borrowingDays), late(late), returned(returned) {}

History::History(QString borrowerId, QString barcode, QString borrowingDate,
                 int borrowingDays, int late, int returned)
    : borrowerId(borrowerId), barcode(barcode),
      borrowingDate(borrowingDate), borrowingDays(borrowingDays), late(late), returned(returned) {}

History::~History() {}

//getters
int History::getId()
{
    return id;
}

QString History::getBorrowerId()
{
    return borrowerId;
}

QString History::getBarcode()
{
    return barcode;
}

QString History::getBorrowingDate()
{
    return borrowingDate;
}

int History::getBorrowingDays()
{
    return borrowingDays;
}

int History::isLate()
{
    return late;
}

int History::isReturned()
{
    return returned;
}

//setters
void History::setBorrowerId(QString borrowerId)
{
    this->borrowerId = borrowerId;
}

void History::setBarcode(QString barcode)
{
    this->barcode = barcode;
}

void History::setBorrowingDate(QString borrowingDate)
{
    this->borrowingDate = borrowingDate;
}

void History::setBorrowingDays(int borrowingDays)
{
    this->borrowingDays = borrowingDays;
}

void History::setLate(int late)
{
    this->late = late;
}

void History::setReturned(int returned)
{
    this->returned = returned;
}
