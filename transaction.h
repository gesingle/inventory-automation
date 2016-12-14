#ifndef TRANSACTION_H
#define TRANSACTION_H

//#include "Customer.h"
#include "movie.h"
#include "clmovietree.h"
#include "comovietree.h"
#include "drmovietree.h"

#include <iostream>
#include <string>

class Transaction
{
	//friend std::ostream& operator<<(std::ostream& outs, const Transaction& trans);

public:
	Transaction();
	~Transaction();

	void setClMovieTree(ClMovieTree *movieRoot);
    void setCoMovieTree(CoMovieTree *movieRoot);
    void setDrMovieTree(DrMovieTree *movieRoot);
	virtual void makeAction() = 0;

protected:
	//virtual void print(std::ostream& outs) const = 0;
	ClMovieTree* clMovieTree;
    CoMovieTree* coMovieTree;
    DrMovieTree* drMovieTree;
};

#endif