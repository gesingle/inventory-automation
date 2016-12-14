//
// Created by Cody Snow on 12/12/2016
//

#ifndef DISPLAYTRANSACTION_H
#define DISPLAYTRANSACTION_H

#include "Transaction.h"

class DisplayTransaction : public Transaction
{
public:
	DisplayTransaction();
	~DisplayTransaction();
	virtual void makeAction() = 0;

};

#endif