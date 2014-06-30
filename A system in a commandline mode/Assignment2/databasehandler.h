#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include "multimediacollection.h"
#include "copycollection.h"
#include "borrower.h"

#include <QtSql>

class DatabaseHandler
{
private:
    QSqlDatabase db;

public:
    DatabaseHandler();
    ~DatabaseHandler();

    bool checkConnection();
    bool checkDatabase();
    void createDatabase();
    void loadDatabase(list<MultimediaCollection> *multiCols,
                      list<CopyCollection> *copyCols,
                      list<Borrower> *borrowers);
    void createTables();
    void initializeDatabase();
    void closeConnection();

    void insertBorrower(Borrower *borrower);
    void insertMultiCollection(MultimediaCollection *multi);
    void insertCopyCollection(CopyCollection *copy);
    void insertMultiCate(list<Category> categories);
    void insertHistory(History *history);
    void updateWhenBorrow(Borrower *borrower, CopyCollection *copy, History *history);
    void updateWhenReturn(Borrower *borrower, CopyCollection *copy, History *history);
};

#endif // DATABASEHANDLER_H
