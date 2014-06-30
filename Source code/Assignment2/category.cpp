#include "category.h"

using namespace std;

Category::Category(){}
Category::Category(int id, QString name): id(id), name(name) {}

Category::~Category(){}

QString Category::toQString()
{
    return name;
}

//getters
int Category::getId()
{
    return id;
}

QString Category::getName()
{
    return name;
}

//setters
void Category::setName(QString name)
{
    this->name = name;
}
