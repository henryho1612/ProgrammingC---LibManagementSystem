#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>

using namespace std;

class Category
{
private:
    int      id;
    QString  name;

public:
    Category();
    Category(int id, QString name);
    ~Category();

    QString toQString();

    //getters
    int getId();
    QString getName();

    //setters
    void setName(QString name);

};

#endif // CATEGORY_H
