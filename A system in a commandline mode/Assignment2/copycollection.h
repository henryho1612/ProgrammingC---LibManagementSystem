#ifndef COPYCOLLECTION_H
#define COPYCOLLECTION_H

#include <QString>

using namespace std;

class CopyCollection
{
private:
    int         id;
    QString     cid;
    QString     barcode;
    QString     status;
    int         borrowingTimes;
    QString      dateBorrowed;
    int         numDayBorrowed;

public:
    CopyCollection();
    CopyCollection(int id, QString cid, QString barcode, QString status, int borrowingTimes);
    ~CopyCollection();

    //getters
    int getId();
    QString getCid();
    QString getBarcode();
    QString getStatus();
    int getBorrowingTimes();
    int getNumDayBorrowed();
    QString getDateBorrowed();

    //setter
    void setCid(QString cid);
    void setBarcode(QString barcode);
    void setStatus(QString status);
    void setBorrowingTimes(int borrowingTimes);
    void setNumDayBorrowed(int days);
    void setDateBorrowed(QString date);

};

#endif // COPYCOLLECTION_H
