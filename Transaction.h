#ifndef TRANSACTION_H
#define TRANSACTION_H

//#include "Customer.h"
#include "Movie.h"
#include "MovieTree.h"

#include <iostream>
#include <string>

class Transaction
{
	//friend std::ostream& operator<<(std::ostream& outs, const Transaction& trans);

public:
	Transaction();
	~Transaction();

	void setMovieTree(MovieTree* movieRoot);
	virtual void makeAction() = 0;

protected:
	//virtual void print(std::ostream& outs) const = 0;
	MovieTree* movieTree;
};

#endif
