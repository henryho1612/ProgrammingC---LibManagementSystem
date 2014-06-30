#include "role.h"

using namespace std;

Role::Role() {}
Role::Role(int id, QString name) : id(id), name(name) {}

Role::~Role() {}

//getters
int Role::getId()
{
    return id;
}

QString Role::getName()
{
    return name;
}

//setters
void Role::setName(QString name)
{
    this->name = name;
}
