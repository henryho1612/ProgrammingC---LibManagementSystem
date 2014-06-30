#ifndef MULTIMEDIACOLLECTION_H
#define MULTIMEDIACOLLECTION_H

#include <QString>
#include <list>
#include "copycollection.h"
#include "collectiontype.h"
#include "collectiondatatype.h"
#include "category.h"

using namespace std;

class MultimediaCollection
{
private:
    int                      id;
    QString                  cid;
    QString                  title;
    CollectionType           collectionType;
    CollectionDataType       dataType;
    QString                  version;
    QString                  publisher;
    int                      recordedYear;
    int                      duration;
    list<Category>           categories;
    list<CopyCollection>     copyCollections;

public:
    MultimediaCollection();
    MultimediaCollection(int id, QString cid, QString title, CollectionType collectionType,
                         CollectionDataType dataType, QString version, QString publisher,
                         int recordedYear, int duration);
    ~MultimediaCollection();

    QString printAllCategories();
    void cleanUp();

    //getters
    int                      getId();
    QString                  getCid();
    QString                  getTitle();
    CollectionType           getCollectionType();
    CollectionDataType       getDataType();
    QString                  getVersion();
    QString                  getPublisher();
    int                      getRecordedYear();
    int                      getDuration();
    list<CopyCollection>     getCopyCollections();
    list<Category>           getCategories();
    int                      getNumCopies();

    //setters
    void setCid(QString cid);
    void setTitle(QString title);
    void setCollectionType(CollectionType collectionType);
    void setDataType(CollectionDataType dataType);
    void setVersion(QString version);
    void setPublisher(QString publisher);
    void setRecordedYear(int recordedYear);
    void setDuration(int duration);
    void setCopyCollections(list<CopyCollection> copyCollections);
    void setCategories(list<Category> categories);
};

#endif // MULTIMEDIACOLLECTION_H
