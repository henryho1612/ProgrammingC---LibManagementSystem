#include "ICollection.h"
#include "IBorrower.h"
#include <list>

using namespace std;

class MultimediaCollection : public ICollection, public IBorrower {
	
public:
	list<Collection> cols;
	list<CopyCollection> copyCols;
	list<Borrower> borrowers;

	MultimediaCollection();
	~MultimediaCollection();

	void showCollections();
	void showCopies();
	void addCollection(Collection);
	void addCopy(CopyCollection);
	void enterCollectionAndCopies();
	void showBorrowers();
	void addBorrower(Borrower);
	void enterBorrower();

	void loadDatabase();
	bool checkCollectionId(string id);
	bool checkBorrowerId(string id);
};
