#ifndef RETURN_H
#define RETURN_H

#include "ActionTransaction.h"
#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"


class Return: public ActionTransaction
{
public:
	Return();
	~Return();
	virtual void makeAction();
	bool makeReturn(Movie& movie);

	//inherits members from ActionTransaction

};

#endif
