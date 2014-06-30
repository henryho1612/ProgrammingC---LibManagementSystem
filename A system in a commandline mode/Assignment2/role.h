#ifndef ROLE_H
#define ROLE_H

#include <QString>

using namespace std;

class Role
{
private:
    int     id;
    QString  name;

public:
    Role();
    Role(int id, QString name);
    ~Role();

    //getter
    int getId();
    QString getName();

    //setter
    void setName(QString name);
};

#endif // ROLE_H
