//
// Created by Cody Snow on 12/12/2016
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

//#include "Customer.h"
#include "Movie.h"
#include "ClMovietree.h"	
#include "CoMovieTree.h"
#include "DrMovieTree.h"

#include <iostream>
#include <string>

class Transaction
{
	//friend std::ostream& operator<<(std::ostream& outs, const Transaction& trans);

public:
	Transaction();
	~Transaction();

	void setClMovieTree(ClMovieTree* movieRoot);
	void setCoMovieTree(CoMovieTree* movieRoot);
	void setDrMovieTree(DrMovieTree* movieRoot);
	virtual void makeAction() = 0;

protected:
	//virtual void print(std::ostream& outs) const = 0;
	ClMovieTree* clMovieTree;
	CoMovieTree* coMovieTree;
	DrMovieTree* drMovieTree;
};

#endif
