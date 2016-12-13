#ifndef BORROW_H
#define BORROW_H

#include "actionTransaction.h"
#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"

#include <iostream>

class Borrow : public ActionTransaction
{
public:
	Borrow();
	~Borrow();
	virtual void makeAction();
	bool makeBorrow(Movie& movie); //may need to handle differently for classics with same title
	
};

#endif

