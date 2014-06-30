#ifndef COLLECTIONDATATYPE_H
#define COLLECTIONDATATYPE_H

#include <QString>

using namespace std;

class CollectionDataType
{
private:
    int     id;
    QString  name;

public:
    CollectionDataType();
    CollectionDataType(int id, QString name);
    ~CollectionDataType();

    //getter
    int getId();
    QString getName();

    //setter
    void setName(QString name);
};

#endif // COLLECTIONDATATYPE_H
