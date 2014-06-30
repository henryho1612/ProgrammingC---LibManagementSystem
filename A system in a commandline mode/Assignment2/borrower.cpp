#include "borrower.h"
#include "history.h"

#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

Borrower::Borrower() {}
Borrower::Borrower(int id, QString borrowerId, QString name, Role role,
                   Department department, QString mobile, int no_returnedLate, int no_borrowed)
    : id(id), borrowerId(borrowerId), name(name), role(role),
      department(department), mobile(mobile), no_returnedLate(no_returnedLate), no_borrowed(no_borrowed) {}

Borrower::~Borrower() {}

void Borrower::cleanUp()
{
    histories.clear();
}


//getters
int Borrower::getId()
{
    return id;
}

QString Borrower::getBorrowerId()
{
    return borrowerId;
}

QString Borrower::getName()
{
    return name;
}

Role Borrower::getRole()
{
    return role;
}

Department Borrower::getDepartment()
{
    return department;
}

QString Borrower::getMobile()
{
    return mobile;
}

int Borrower::getNoReturnedLate()
{
    return no_returnedLate;
}

int Borrower::getNoBorrowed()
{
    return no_borrowed;
}

list<History> Borrower::getHistories()
{
    return histories;
}

//setters
void Borrower::setBorrowerId(QString borrowerId)
{
    this->borrowerId = borrowerId;
}

void Borrower::setName(QString name)
{
    this->name = name;
}

void Borrower::setRole(Role role)
{
    this->role = role;
}

void Borrower::setDepartment(Department department)
{
    this->department = department;
}

void Borrower::setMobile(QString mobile)
{
    this->mobile = mobile;
}

void Borrower::setNoReturnedLate(int no_returnedLate)
{
    this->no_returnedLate = no_returnedLate;
}

void Borrower::setNoBorrowed(int no_borrowed)
{
    this->no_borrowed = no_borrowed;
}

void Borrower::setHistories(list<History> histories)
{
    this->histories = histories;
}
