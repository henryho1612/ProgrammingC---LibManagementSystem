#include "borrower.h"
#include <iostream>
using namespace std;

Borrower::Borrower(){}
Borrower::Borrower(string id, string n, string t, string d, string m, int num, int numlate) :
id(id), name(n), type(t), department(d), mobile(m), numItemBorrow(num), numItemLateBorrow(numlate) {}

Borrower::~Borrower()
{
	cout << "Borrower " << id << " is deleted\n";
}

string Borrower::getId(){return id;}
string Borrower::getName(){return name;}
string Borrower::getType(){return type;}
string Borrower::getDepartment(){return department;}
string Borrower::getMobile(){return mobile;}
int Borrower::getNumItemBorrow(){return numItemBorrow;}
int Borrower::getNumItemLateBorrow(){return numItemLateBorrow;}
void Borrower::setId(string i){id = i;}
void Borrower::setName(string n){name = n;}
void Borrower::setType(string t){type = t;}
void Borrower::setDepartment(string d){department = d;}
void Borrower::setMobile(string m){mobile = m;}
void Borrower::setNumItemBorrow(int num){numItemBorrow = num;}
void Borrower::setNumItemLateBorrow(int numLate){numItemLateBorrow = numLate;}