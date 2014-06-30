#ifndef COLLECTIONTYPE_H
#define COLLECTIONTYPE_H

#include <QString>

using namespace std;

class CollectionType
{
private:
    int     id;
    QString  name;

public:
    CollectionType();
    CollectionType(int id, QString name);
    ~CollectionType();

    //getter
    int getId();
    QString getName();

    //setter
    void setName(QString name);
};

#endif // COLLECTIONTYPE_H
