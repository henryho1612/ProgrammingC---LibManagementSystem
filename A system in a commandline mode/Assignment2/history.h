#ifndef HISTORY_H
#define HISTORY_H

#include <QString>

using namespace std;

class History
{
private:
    int         id;
    QString      borrowerId;
    QString      barcode;
    QString      borrowingDate;
    int         borrowingDays;
    int         late;
    int         returned;

public:
    History() {}
    History(int id, QString borrowerId, QString barcode, QString borrowingDate,
            int borrowingDays, int late, int returned);
    History(QString borrowerId, QString barcode, QString borrowingDate,
            int borrowingDays, int late, int returned);
    ~History();

    //getters
    int getId();
    QString getBorrowerId();
    QString getBarcode();
    QString getBorrowingDate();
    int getBorrowingDays();
    int isLate();
    int isReturned();

    //setters
    void setBorrowerId(QString borrowerId);
    void setBarcode(QString barcode);
    void setBorrowingDate(QString borrowingDate);
    void setBorrowingDays(int borrowingDays);
    void setLate(int late);
    void setReturned(int returned);
};

#endif // HISTORY_H
