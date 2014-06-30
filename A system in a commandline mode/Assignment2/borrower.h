#ifndef BORROWER_H
#define BORROWER_H

#include "role.h"
#include "history.h"
#include "department.h"
#include "role.h"

#include <QString>
#include <list>

using namespace std;

class Borrower
{
private:
    int             id;
    QString          borrowerId;
    QString          name;
    Role            role;
    Department      department;
    QString          mobile;
    int             no_returnedLate;
    int             no_borrowed;
    list<History>  histories;

public:
    Borrower();
    Borrower(int id, QString borrowerId, QString name, Role role, Department department,
             QString mobile, int no_returnedLate, int no_borrowed);
    ~Borrower();

    void cleanUp();

    //getters
    int             getId();
    QString         getBorrowerId();
    QString         getName();
    Role            getRole();
    Department      getDepartment();
    QString         getMobile();
    int             getNoReturnedLate();
    int             getNoBorrowed();
    list<History>   getHistories();

    //setters
    void setBorrowerId(QString borrowerId);
    void setName(QString name);
    void setRole(Role role);
    void setDepartment(Department department);
    void setMobile(QString mobile);
    void setNoReturnedLate(int no_returnedLate);
    void setNoBorrowed(int no_borrowed);
    void setHistories(list<History> histories);
};

#endif // BORROWER_H
