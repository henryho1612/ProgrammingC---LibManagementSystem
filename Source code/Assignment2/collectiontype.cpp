#include "collectiontype.h"

using namespace std;

CollectionType::CollectionType() {}
CollectionType::CollectionType(int id, QString name) : id(id), name(name) {}

CollectionType::~CollectionType() {}

//getters
int CollectionType::getId()
{
    return id;
}

QString CollectionType::getName()
{
    return name;
}

//setters
void CollectionType::setName(QString name)
{
    this->name = name;
}
