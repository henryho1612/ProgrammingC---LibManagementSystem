#include "multimediacollection.h"
#include <iostream>
#include <string>

using namespace std;

void mainMenu();
void enterDataMenu();
void operationMenu();
void reportMenu();

int main()
{	
	/*
	MultimediaCollection mulCollection;
	mulCollection.loadDatabase();
	cout << "\n";
	mulCollection.showCollections();
	cout << "\n";
	mulCollection.showCopies();
	cout << "\n";
	mulCollection.showBorrowers();
	*/

	//mulCollection.enterCollectionAndCopies();
	//mulCollection.enterBorrower();
	
	//mulCollection.showCollections();
	//mulCollection.showCopies();
	//mulCollection.showBorrowers();
	

	/*MAIN MENU IMPLEMENTATION
	string choice;
	mainMenu();
	
	while(getline(cin, choice))
	{	
		if(choice.empty())
		{
			cout << "Exit \n";
			break;
		} else
		{
			if(choice == "1")
			{
				enterDataMenu();
				string menu1;
				
				while(getline(cin, menu1))
				{
					if(menu1.empty())
					{
						mainMenu();
						break;
					} else if(menu1 == "1")
					{	
						cout << "EnterDataMenu - 1 method\n";
						mainMenu();
						break;
					} else if(menu1 == "2")
					{
						cout << "EnterDataMenu -2 method\n";
						mainMenu();
						break;
					} else
					{
						cout << "Invalid choice! Select (1-2) or press Enter to return to main menu: ";
					}
				}
			} else if(choice == "2")
			{
				operationMenu();
				string menu2;
				
				while(getline(cin, menu2))
				{
					if(menu2.empty())
					{
						mainMenu();
						break;
					} else if(menu2 == "1")
					{
						cout << "operationMenu - 1 method\n";
						mainMenu();
						break;
					} else if(menu2 == "2")
					{
						cout << "operationMenu - 2 method\n";
						mainMenu();
						break;
					} else if(menu2 == "3")
					{
						cout << "operationMenu - 3 method\n";
						mainMenu();
						break;
					} else
					{
						cout << "Invalid choice! Select (1-4) or press Enter to return to main menu: ";
					}
				}
			} else if(choice == "3")
			{
				reportMenu();
				string menu3;
				
				while(getline(cin, menu3))
				{
					if(menu3.empty())
					{
						mainMenu();
						break;
					} else if(menu3 == "1")
					{
						cout << "reportMenu - 1 method\n";
						mainMenu();
						break;
					} else if(menu3 == "2")
					{
						cout << "reportMenu - 2 method\n";
						mainMenu();
						break;
					} else if(menu3 == "3")
					{
						cout << "reportMenu - 3 method\n";
						mainMenu();
						break;
					} else if(menu3 == "4")
					{
						cout << "reportMenu - 4 method\n";
						mainMenu();
						break;
					} else
					{
						cout << "Invalid choice! Select (1-4) or press Enter to return to main menu: ";
					}
				}
			} else
			{
				cout << "Invalid choice! Select (1-3) or Enter to exit: ";
			}
		}
	}
	*/
	system("pause");

	return 0;
}

void mainMenu()
{
	cout << "\nMULTIMEDIA LIBRARY COLLECITONS AND SYSTEM SERVICE\n";
	cout << "=================================================\n";
	cout << "1 - ENTERING DATA\n";
	cout << "2 - EVERYDAY OPERATIONS\n";
	cout << "3 - SHOW REPORT\n";
	cout << "ENTER TO EXIT\n";
	cout << "Enter your choice (1-3) or press Enter to exit: ";
}

void enterDataMenu()
{
	cout << "\nENTERING DATA MENU\n";
	cout << "===================\n";
	cout << "1 - ENTERING A NEW COLLECTION AND COPIES\n";
	cout << "2 - ENTERING A NEW BORROWER\n";
	cout << "ENTER TO RETURN MAIN MENU\n";
	cout << "Enter your choice (1-2) or press Enter to return to main menu: ";
}

void operationMenu()
{
	cout << "\nEVERYDAY OPERATIONS\n";
	cout << "===================\n";
	cout << "1 - BORROW A COLLECTION\n";
	cout << "2 - RETURN A COLLECTION\n";
	cout << "3 - CHANGE STATUS OF AN IEM\n";
	cout << "ENTER TO RETURN MAIN MENU\n";
	cout << "Enter your choice (1-3) or press Enter to return to main menu: "; 
}

void reportMenu()
{
	cout << "\nREPORTS\n";
	cout << "========\n";
	cout << "1 - LIST ALL COLLECTIONS\n";
	cout << "2 - LIST WITH COPIES OF ITEMS\n";
	cout << "3 - LIST OF BORROWERS\n";
	cout << "4 - LIST OF OVERDUE BORROWERS\n";
	cout << "ENTER TO RETURN MAIN MENU\n";
	cout << "Enter your choice (1-4) or press Enter to return to main menu: ";
}