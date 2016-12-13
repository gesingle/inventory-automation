#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

class Transaction
{
	friend std::ostream& operator<<(std::ostream& outs, const Transaction& trans);

public:
	Transaction();
	virtual ~Transaction();

	virtual bool makeAction(std::string& line) = 0;

private:
	//virtual void print(std::ostream& outs) const = 0;
};

#endif
