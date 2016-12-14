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

void Transaction::setMovieTree(MovieTree* movieRoot)
{
	movieTree = movieRoot;
}