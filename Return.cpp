#include "Return.h"

Return::Return()
{
}

Return::~Return()
{
}

void Return::makeAction()
{
	if (movie != NULL)
		makeReturn(*movie);
}

bool Return::makeReturn(Movie& movie)
{
	if (borrowed)
	{
		int stockNum = movie.getStock() + 1;
		movie.setStock(stockNum); //needs updated movie classes
		return true;
	}
	else
	{
		cout << "Movie has not been borrowed" << endl;
		return false;
	}
}