#include "Borrow.h"

Borrow::Borrow()
{
}

Borrow::~Borrow()
{
}

void Borrow::makeAction()
{
	if (movie != NULL)
	{
		makeBorrow(*movie);
	}
}

bool Borrow::makeBorrow(Movie& movie)
{
	if (movie.getStock() <= 0)
	{
		return false; //may need to handle case for multiple classics with same title
	}
	else
	{
		int stockNum = movie.getStock() - 1;
		movie.setStock(stockNum);

		borrowed = true;
		return true;
	}
}