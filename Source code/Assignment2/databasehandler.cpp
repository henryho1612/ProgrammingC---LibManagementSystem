#include "databasehandler.h"
#include <QString>

using namespace std;

DatabaseHandler::DatabaseHandler(){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("dhis");
    qDebug() << db.connectionName();
}

DatabaseHandler::~DatabaseHandler(){ delete &db; QSqlDatabase::removeDatabase(db.connectionName());}

void DatabaseHandler::closeConnection()
{
    db.close();
}

bool DatabaseHandler::checkConnection()
{
    if (db.userName() == "root" && db.password() == "dhis" )
        return true;
    else
        return false;
}

bool DatabaseHandler::checkDatabase()
{
    db.open();

    QString query = "SHOW DATABASES LIKE 'mcdb1';";
    QSqlQuery q = db.exec(query);

    if(!q.next())
        return false;

    db.close();

    return true;
}

void DatabaseHandler::createDatabase()
{
    db.open();

    QString query = "CREATE DATABASE mcdb1;";
    db.exec(query);

    db.close();
}

void DatabaseHandler::createTables()
{
    db.open();
    db.exec("USE mcdb1");

    QString query = "CREATE TABLE IF NOT EXISTS `role`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT, "\
            "`name` varchar(45) NOT NULL,PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `department`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`name` varchar(45) NOT NULL,PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `borrower`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`borrowerId` varchar(15) NOT NULL,"\
            "`name` varchar(50) NOT NULL,"\
            "`idRole` int(11) NOT NULL,"\
            "`idDepartment` int(11) NOT NULL,"\
            "`mobile` varchar(20) NOT NULL,"\
            "`no_returnedLate` int(11) NOT NULL,"\
            "`no_borrowingBooks` int(11) NOT NULL, PRIMARY KEY (`id`),"\
            "KEY `idDepartment_idx` (`idDepartment`),"\
            "KEY `idRole_idx` (`idRole`), CONSTRAINT `idRole`"\
            "FOREIGN KEY (`idRole`)"\
            "REFERENCES `role` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,"\
            "CONSTRAINT `idDepartment` FOREIGN KEY (`idDepartment`) REFERENCES `department` (`id`)"\
            "ON DELETE NO ACTION ON UPDATE NO ACTION) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `collectiondatatype`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`name` varchar(20) NOT NULL,PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `collectiontype`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`name` varchar(20) NOT NULL,PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `multimedia`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`cid` varchar(50) NOT NULL,"\
            "`title` varchar(255) NOT NULL,"\
            "`idCollectionType` int(11) NOT NULL,"\
            "`idDataType` int(11) NOT NULL,"\
            "`version` varchar(10) NOT NULL,"\
            "`publisher` varchar(150) NOT NULL,"\
            "`recordedYear` int(11) NOT NULL,"\
            "`duration` int(11) NOT NULL, PRIMARY KEY (`id`),"\
            "KEY `idCollectionType_idx` (`idCollectionType`),"\
            "KEY `idDataType_idx` (`idDataType`),"\
            "CONSTRAINT `idCollectionType`"\
            "FOREIGN KEY (`idCollectionType`) REFERENCES `collectiontype` (`id`)"\
            "ON DELETE NO ACTION ON UPDATE NO ACTION,"\
            "CONSTRAINT `idDataType` FOREIGN KEY (`idDataType`) REFERENCES `collectiondatatype` (`id`)"\
            "ON DELETE NO ACTION ON UPDATE NO ACTION) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `copycollection`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`cid` varchar(50) NOT NULL,"\
            "`barcode` varchar(100) NOT NULL,"\
            "`status` varchar(20) NOT NULL,"\
            "`borrowingTimes` int(11) NOT NULL,"\
            "`numDayBorrowed` int(11) NOT NULL default '0',"\
            "`dateBorrowed` varchar(255) NOT NULL default '',"\
            "PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `category`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`name` varchar(150) NOT NULL,PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;";\
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `categorymultimedia`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`idCate` int(11) NOT NULL,"\
            "`idMultiCollection` varchar(10) NOT NULL,"\
            "PRIMARY KEY (`id`),"\
            "KEY `idCate_idx` (`idCate`),"\
            "CONSTRAINT `idCate` FOREIGN KEY (`idCate`)"\
            "REFERENCES `category` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    query = "CREATE TABLE IF NOT EXISTS `history`"\
            "(`id` int(11) NOT NULL AUTO_INCREMENT,"\
            "`borrowerId` varchar(15) NOT NULL,"\
            "`barcode` varchar(100) NOT NULL,"\
            "`borrowingDate` varchar(20) NOT NULL,"\
            "`borrowingDays` int(11) NOT NULL,"\
            "`late` tinyint(4) NOT NULL,"\
            "`isReturned` tinyint(4) NOT NULL,"\
            "PRIMARY KEY (`id`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;";
    db.exec(query);

    db.close();
}

void DatabaseHandler::initializeDatabase()
{
    db.open();
    db.exec("USE mcdb1");

    QString query = "INSERT INTO `role` VALUES (1,'Student'),(2,'Lecturer');";
    db.exec(query);

    query = "INSERT INTO `department` VALUES (1,'BIT');";
    db.exec(query);

    query = "INSERT INTO `borrower` VALUES "\
            "(1,'s3357671','Henry Ho',1,1,'0932141483',0,2),"\
            "(2,'s3357678','Ngo Tan Thinh',1,1,'0908147474',0,2),"\
            "(3,'s3357679','Nguyen Hoang Tuan',1,1,'01666546889',1,2);";
    db.exec(query);

    query = "INSERT INTO `collectiondatatype` VALUES (1,'Images'),(2,'Video'),(3,'Audio');";
    db.exec(query);

    query = "INSERT INTO `collectiontype` VALUES (1,'Dvd'),(2,'Vcd'),(3,'Blu-ray');";
    db.exec(query);

    query = "INSERT INTO `multimedia` VALUES "\
            "(1,'B0001','Frozen',1,2,'1','Walt Disney',2013,108),"\
            "(2,'A0001','Tyler Perry s A Madea Christmas',2,2,'1',' Tyler Perry Company',2013,105),"\
            "(3,'C0001','Harry Porter',3,1,'1','RMIT Present',2013,105);";
    db.exec(query);

    query = "INSERT INTO `category` VALUES (1,'Animation'),(2,'Adventure'),(3,'Fantasy'),(4,'Comedy'),(5,'Drama');";
    db.exec(query);

    query = "INSERT INTO `categorymultimedia` VALUES (1,4,'2'),(2,5,'2'),(3,1,'1'),(4,2,'1'),(5,4,'1');";
    db.exec(query);

    query = "INSERT INTO `copycollection` VALUES "\
            "('1', 'B0001', 'B0001121220131', 'In Storeroom', '0', '0', ''),"\
            "('2', 'B0001', 'B0001121220132', 'Lost', '1', '0', ''),"\
            "('3', 'B0001', 'B0001121220133', 'Borrowed', '1', '15', '12-12-2013-09-10'),"\
            "('4', 'B0001', 'B0001121220134', 'In Library', '1', '0', ''),"\
            "('5', 'A0001', 'A0001121220131', 'In Storeroom', '0', '0', ''),"\
            "('6', 'A0001', 'A0001121220132', 'Lost', '1', '0', ''),"\
            "('7', 'A0001', 'A0001121220133', 'Borrowed', '1', '15', '12-09-2013-15-00'),"\
            "('8', 'A0001', 'A0001121220134', 'In Library', '1', '0', ''),"\
            "('9', 'C0001', 'C0001100920131', 'Borrowed', '3', '3', '12-09-2013-16-00'),"\
            "('10', 'C0001', 'C0001100920132', 'Borrowed', '1', '5', '12-09-2013-00-20'),"\
            "('11', 'C0001', 'C0001100920133', 'Borrowed', '2', '7', '12-12-2013-10-00'),"\
            "('12', 'C0001', 'C0001100920134', 'Borrowed', '1', '7', '12-12-2013-10-00');";
    db.exec(query);

    query = "INSERT INTO `history` VALUES"\
            "(1,'s3357671','B0001121220133','12-12-2013-00-00',1,1,0),"\
            "(2,'s3357671','A0001121220133','10/12-2013-00-00',2,1,0),"\
            "(3,'s3357679','A0001121220133','01-12-2013-00-00',12,0,1),"\
            "(4,'s3357679','B0001121220133','01-12-2013-00-00',7,1,0),"\
            "(5,'s3357678','B0001121220134','10-12-2013-00-00',7,1,0),"\
            "(6,'s3357678','A0001121220134','10-12-2013-00-00',7,1,0);";
    db.exec(query);

    db.close();
}

void DatabaseHandler::loadDatabase(list<MultimediaCollection> *multiCols,
                                   list<CopyCollection> *copies,
                                   list<Borrower> *borrowers)
{
    db.open();
    db.exec("USE mcdb1");

    QVariant v;
    QSqlQuery subQ;
    list<Category> categories;
    list<History> histories;
    list<CopyCollection> copiesOfCollection;

    //Load all multimedia collections
    QSqlQuery q("SELECT * FROM multimedia;");
    while(q.next())
    {
        int idDataType = q.value(4).toInt();
        int idCollectionType = q.value(3).toInt();

        subQ.prepare("SELECT * FROM collectiondatatype WHERE id = :id");
        subQ.bindValue(":id", idDataType);
        if (!subQ.exec())
        {
            qDebug() << subQ.lastError().text();
            return;
        }
        while (subQ.next())
        {
            v = subQ.value(1).toString();
        }
        CollectionDataType mcDataType(idDataType, v.toString());

        subQ.prepare("SELECT * FROM collectiontype WHERE id = :id");
        subQ.bindValue(":id", idCollectionType);
        if (!subQ.exec())
        {
            qDebug() << subQ.lastError().text();
            return;
        }
        while (subQ.next())
        {
            v = subQ.value(1).toString();
        }
        CollectionType mcType(idCollectionType, v.toString());

        MultimediaCollection mc(q.value(0).toInt(),
                                q.value(1).toString(),
                                q.value(2).toString(),
                                mcType,
                                mcDataType,
                                q.value(5).toString(),
                                q.value(6).toString(),
                                q.value(7).toInt(),
                                q.value(8).toInt());
        //qDebug() << q.value(0).toInt() << q.value(1).toString() << q.value(2).toString();

        //Load all categories into Collection
        subQ.prepare("SELECT * FROM categorymultimedia WHERE id =:id");
        subQ.bindValue(":id", mc.getId());
        if (!subQ.exec())
        {
            qDebug() << subQ.lastError().text();
            return;
        }
        while (subQ.next())
        {
            QSqlQuery cateQuery;
            cateQuery.prepare("SELECT * FROM category WHERE id=:id");
            cateQuery.bindValue(":id", subQ.value(1).toInt());
            if(!cateQuery.exec())
            {
                qDebug() << cateQuery.lastError().text();
                return;
            }
            while(cateQuery.next())
            {
                Category category(subQ.value(1).toInt(), cateQuery.value(1).toString());
                categories.push_back(category);
            }
        }
        mc.setCategories(categories);
        categories.clear();

        //Load all copy collections into copies and each collection
        subQ.prepare("SELECT * FROM copycollection;");
        subQ.exec();
        while(subQ.next())
        {
            CopyCollection copy(subQ.value(0).toInt(),
                                subQ.value(1).toString(),
                                subQ.value(2).toString(),
                                subQ.value(3).toString(),
                                subQ.value(4).toInt());
            copy.setDateBorrowed(subQ.value(6).toString());
            copy.setNumDayBorrowed(subQ.value(5).toInt());

            if(q.value(1).toString() == copy.getCid())
            {
                copiesOfCollection.push_back(copy);
                copies->push_back(copy);
            }
        }

        mc.setCopyCollections(copiesOfCollection);
        copiesOfCollection.clear();

        multiCols->push_back(mc);
    }

    //Load borrowers
    q.prepare("SELECT * FROM borrower;");
    q.exec();
    while(q.next())
    {
        int idRole = q.value(3).toInt();
        int idDepartment = q.value(4).toInt();

        subQ.prepare("SELECT * FROM role WHERE id = :id");
        subQ.bindValue(":id", idRole);
        if (!subQ.exec())
        {
            qDebug() << subQ.lastError().text();
            return;
        }
        while (subQ.next())
        {
            v = subQ.value(1).toString();
        }
        Role bRole(idRole, v.toString());

        subQ.prepare("SELECT * FROM department WHERE id = :id");
        subQ.bindValue(":id", idDepartment);
        if (!subQ.exec())
        {
            qDebug() << subQ.lastError().text();
            return;
        }
        while (subQ.next())
        {
            v = subQ.value(1).toString();
        }
        Department bDepartment(idDepartment, v.toString());

        Borrower borrower(q.value(0).toInt(),
                          q.value(1).toString(),
                          q.value(2).toString(),
                          bRole, bDepartment,
                          q.value(5).toString(),
                          q.value(6).toInt(),
                          q.value(7).toInt());

        //Load histories into each borrowers
        subQ.prepare("SELECT * FROM history");
        subQ.exec();
        while(subQ.next())
        {
            if(borrower.getBorrowerId() == subQ.value(1).toString())
            {
                History history(subQ.value(0).toInt(),
                                subQ.value(1).toString(),
                                subQ.value(2).toString(),
                                subQ.value(3).toString(),
                                subQ.value(4).toInt(),
                                subQ.value(5).toInt(),
                                subQ.value(6).toInt());
                histories.push_back(history);
            }
        }
        borrower.setHistories(histories);
        histories.clear();

        borrowers->push_back(borrower);
    }

    db.close();
}

void DatabaseHandler::insertBorrower(Borrower *borrower)
{
    db.open();
    db.exec("USE mcdb1");

    QSqlQuery query;
    query.prepare("INSERT INTO borrower(borrowerId, name, idRole, idDepartment, mobile, no_returnedLate, no_borrowingBooks)VALUES(?,?,?,?,?,?,?);");
    //qDebug() << borrower->getBorrowerId() << "|" << borrower->getRole().getId() << "|" << borrower->getDepartment().getId() << "|" << borrower->getMobile() << "|" << borrower->getNoReturnedLate() << "|" << borrower->getNoBorrowed();
    query.bindValue(0, borrower->getBorrowerId());
    query.bindValue(1, borrower->getName());
    query.bindValue(2, borrower->getRole().getId());
    query.bindValue(3, borrower->getDepartment().getId());
    query.bindValue(4, borrower->getMobile());
    query.bindValue(5, borrower->getNoReturnedLate());
    query.bindValue(6, borrower->getNoBorrowed());
    query.exec();

    db.close();
}

void DatabaseHandler::insertMultiCollection(MultimediaCollection *multi)
{
    db.open();
    db.exec("USE mcdb1");

    QSqlQuery query;
    query.prepare("INSERT INTO multimedia(cid,title,idCollectionType,idDataType,version,publisher,recordedYear,duration)"\
                  "VALUES (:cid,:title, :idCollectionType, :idDataType, :version, :publisher, :recordedYear, :duration);");
    query.bindValue(":cid", multi->getCid());
    query.bindValue(":title", multi->getTitle());
    query.bindValue(":idCollectionType", multi->getCollectionType().getId());
    query.bindValue(":idDataType", multi->getDataType().getId());
    query.bindValue(":version", multi->getVersion());
    query.bindValue(":publisher", multi->getPublisher());
    query.bindValue(":recordedYear", multi->getRecordedYear());
    query.bindValue(":duration", multi->getDuration());
    query.exec();

    db.close();
}

void DatabaseHandler::insertCopyCollection(CopyCollection *copy)
{
    db.open();
    db.exec("USE mcdb1");

    QSqlQuery query;
    query.prepare("INSERT INTO copycollection (cid, barcode, status, borrowingTimes)"\
                  "VALUES (:cid, :barcode, :status, :borrowingTimes);");
    query.bindValue(":cid", copy->getCid());
    query.bindValue(":barcode", copy->getBarcode());
    query.bindValue(":status", copy->getStatus());
    query.bindValue(":borrowingTimes", copy->getBorrowingTimes());
    query.exec();

    db.close();
}

void DatabaseHandler::insertMultiCate(list<Category> categories)
{
    db.open();
    db.exec("USE mcdb1");

    int idMultiCollection;
    QSqlQuery q;
    q.prepare("SELECT MAX(id) AS id FROM multimedia");
    if (!q.exec())
    {
        qDebug() << q.lastError().text();
        return;
    }
    while (q.next())
    {
        idMultiCollection = q.value(0).toInt();
    }

    list<Category>::iterator it = categories.begin();
    while (it != categories.end())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO categorymultimedia (idCate,idMultiCollection)"\
                      "VALUES (:idCate, :idMultiCollection);");
        query.bindValue(":idCate", it->getId() );
        query.bindValue(":idMultiCollection", idMultiCollection);
        query.exec();

        *it++;
    }

    db.close();
}

void DatabaseHandler::updateWhenBorrow(Borrower *borrower, CopyCollection *copy, History *history)
{
    db.open();
    db.exec("USE mcdb1");

    QSqlQuery query;

    //Update borrower
    query.prepare("UPDATE borrower SET no_borrowingBooks = ? WHERE borrowerId = ?");
    query.bindValue(0, borrower->getNoBorrowed());
    query.bindValue(1, borrower->getBorrowerId());
    query.exec();

    //Update copy collection
    query.prepare("UPDATE copycollection SET status=?, borrowingTimes=?, numDayBorrowed=?, dateBorrowed=? WHERE barcode=?;");
    query.bindValue(0, copy->getStatus());
    query.bindValue(1, copy->getBorrowingTimes());
    query.bindValue(2, copy->getNumDayBorrowed());
    query.bindValue(3, copy->getDateBorrowed());
    query.bindValue(4, copy->getBarcode());
    query.exec();

    //Insert history
    query.prepare("INSERT INTO history (borrowerId, barcode, borrowingDate, borrowingDays, late, isReturned) VALUES (?,?,?,?,?,?)");
    query.bindValue(0, borrower->getBorrowerId());
    query.bindValue(1, copy->getBarcode());
    query.bindValue(2, copy->getDateBorrowed());
    query.bindValue(3, copy->getNumDayBorrowed());
    query.bindValue(4, history->isLate());
    query.bindValue(5, history->isReturned());
    query.exec();

    db.close();
}

void DatabaseHandler::updateWhenReturn(Borrower *borrower, CopyCollection *copy, History *history)
{
     db.open();
     db.exec("USE mcdb1");

     QSqlQuery query;
     query.prepare("UPDATE borrower SET no_returnedLate = ? WHERE borrowerId = ?;");
     query.bindValue(0, borrower->getNoReturnedLate());
     query.bindValue(1, borrower->getBorrowerId());
     query.exec();

     query.prepare("UPDATE history SET isLate=?, isReturned=? WHERE borrowerId=? AND barcode=? AND isReturned=? AND borrowingDate=?;");
     query.bindValue(0,history->isLate());
     query.bindValue(1,history->isReturned());
     query.bindValue(2,history->getBorrowerId());
     query.bindValue(3,history->getBarcode());
     query.bindValue(4,1);
     query.bindValue(5,history->getBorrowingDate());
     query.exec();

     query.prepare("UPDATE copycollection SET status=?, dateBorrowed=?, numDaysBorrowed=? WHERE barcode=?");
     query.bindValue(0, copy->getStatus());
     query.bindValue(1, copy->getDateBorrowed());
     query.bindValue(2, copy->getNumDayBorrowed());
     query.bindValue(3, copy->getBarcode());
     query.exec();

     db.close();
}

