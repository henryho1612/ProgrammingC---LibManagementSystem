#include "multimediacollection.h"

#include <iomanip>
#include <iostream>

using namespace std;

MultimediaCollection::MultimediaCollection() {}
MultimediaCollection::MultimediaCollection(int id, QString cid, QString title, CollectionType collectionType,
                                           CollectionDataType dataType, QString version, QString publisher,
                                           int recordedYear, int duration)
    : id(id), cid(cid), title(title), collectionType(collectionType), dataType(dataType),
      version(version), publisher(publisher), recordedYear(recordedYear), duration(duration) {}

MultimediaCollection::~MultimediaCollection() {}

QString MultimediaCollection::printAllCategories()
{
    QString allCate;
    unsigned int count = 0;
    list<Category>::iterator it = categories.begin();
    while (it != categories.end())
    {
        if ((count) == (categories.size() - 1))
        {
            allCate.append(it->toQString());
        }
        else
        {
            allCate.append(it->toQString() + ", ");
        }

        count++;
        *it++;
    }
    return allCate;
}

void MultimediaCollection::cleanUp()
{
    copyCollections.clear();
    categories.clear();
}

//getters
int MultimediaCollection::getId()
{
    return id;
}

QString MultimediaCollection::getCid()
{
    return cid;
}

QString MultimediaCollection::getTitle()
{
    return title;
}

CollectionType MultimediaCollection::getCollectionType()
{
    return collectionType;
}

CollectionDataType MultimediaCollection::getDataType()
{
    return dataType;
}

QString MultimediaCollection::getVersion()
{
    return version;
}

QString MultimediaCollection::getPublisher()
{
    return publisher;
}

int MultimediaCollection::getRecordedYear()
{
    return recordedYear;
}

int MultimediaCollection::getDuration()
{
    return duration;
}

list<CopyCollection> MultimediaCollection::getCopyCollections()
{
    return copyCollections;
}

list<Category> MultimediaCollection::getCategories()
{
    return categories;
}

int MultimediaCollection::getNumCopies()
{
    return copyCollections.size();
}

//setters
void MultimediaCollection::setCid(QString cid)
{
    this->cid = cid;
}

void MultimediaCollection::setTitle(QString title)
{
    this->title = title;
}

void MultimediaCollection::setCollectionType(CollectionType collectionType)
{
    this->collectionType = collectionType;
}

void MultimediaCollection::setDataType(CollectionDataType dataType)
{
    this->dataType = dataType;
}

void MultimediaCollection::setVersion(QString version)
{
    this->version = version;
}

void MultimediaCollection::setPublisher(QString publisher)
{
    this->publisher = publisher;
}

void MultimediaCollection::setRecordedYear(int recordedYear)
{
    this->recordedYear = recordedYear;
}

void MultimediaCollection::setDuration(int duration)
{
    this->duration = duration;
}

void MultimediaCollection::setCopyCollections(list<CopyCollection> copyCollections)
{
    this->copyCollections = copyCollections;
}

void MultimediaCollection::setCategories(list<Category> categories)
{
    this->categories = categories;
}
