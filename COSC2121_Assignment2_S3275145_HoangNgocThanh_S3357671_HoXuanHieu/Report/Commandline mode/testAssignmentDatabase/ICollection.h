#include <iostream>
#include "collection.h"
#include "copycollection.h"

class ICollection {
public:
	virtual ~ICollection() {cout << "ICollection is deleted!\n";};
	virtual void addCollection(Collection col) = 0;
	virtual void addCopy(CopyCollection cc) = 0;
	virtual void showCollections() = 0;
	virtual void showCopies() = 0;
	virtual void enterCollectionAndCopies() = 0;
};