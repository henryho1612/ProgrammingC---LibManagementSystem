#include "mainwindow.h"
#include "databasehandler.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    list<MultimediaCollection> multiCollections;
    list<CopyCollection> copies;
    list<Borrower> borrowers;

    DatabaseHandler dbHandler;
    if(!dbHandler.checkConnection()) {
        QMessageBox::critical(0, QObject::tr("Database Error"), "Can't open database!");
        a.exit();
    }
    else
    {
        if(!dbHandler.checkDatabase())
        {
            QMessageBox::about(0, QObject::tr("Information"),
                               "New mcdb database will be added to your database");
            dbHandler.createDatabase();
            dbHandler.createTables();
            dbHandler.initializeDatabase();
        }

        dbHandler.loadDatabase(&multiCollections, &copies , &borrowers);
        qDebug() << "main:" << multiCollections.size();
        w.setDb(multiCollections, copies, borrowers, &dbHandler);
        w.show();
    }

    dbHandler.closeConnection();

    return a.exec();
}
