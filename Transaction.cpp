//
// Created by Cody Snow on 12/12/2016
//

#include "Transaction.h"

Transaction::Transaction()
{
}
Transaction::~Transaction()
{
}

void Transaction::setClMovieTree(ClMovieTree* movieRoot)
{
	clMovieTree = movieRoot;
}

void Transaction::setCoMovieTree(CoMovieTree* movieRoot)
{
	coMovieTree = movieRoot;
}

void Transaction::setDrMovieTree(DrMovieTree* movieRoot)
{
	drMovieTree = movieRoot;
}
