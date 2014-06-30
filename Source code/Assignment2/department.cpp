#include "department.h"

using namespace std;

Department::Department() {}
Department::Department(int id, QString name) : id(id), name(name) {}

Department::~Department() {}

//getters
int Department::getId()
{
    return id;
}

QString Department::getName()
{
    return name;
}

//setters
void Department::setName(QString name)
{
    this->name = name;
}
