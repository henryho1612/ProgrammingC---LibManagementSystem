#include <iostream>
#include "borrower.h"

class IBorrower {
public:
	virtual ~IBorrower() {cout << "IBorrower is deleted!\n";};

};