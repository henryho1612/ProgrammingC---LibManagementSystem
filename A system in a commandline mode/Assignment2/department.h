#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QString>

using namespace std;

class Department
{
private:
    int         id;
    QString      name;

public:
    Department();
    Department(int id, QString name);
    ~Department();

    //getters
    int getId();
    QString getName();

    //setters
    void setName(QString name);
};

#endif // DEPARTMENT_H
