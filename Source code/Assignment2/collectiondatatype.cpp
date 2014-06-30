#include "collectiondatatype.h"

using namespace std;

CollectionDataType::CollectionDataType() {}
CollectionDataType::CollectionDataType(int id, QString name) : id(id), name(name) {}

CollectionDataType::~CollectionDataType() {}

//getters
int CollectionDataType::getId()
{
    return id;
}

QString CollectionDataType::getName()
{
    return name;
}

//setters
void CollectionDataType::setName(QString name)
{
    this->name = name;
}
