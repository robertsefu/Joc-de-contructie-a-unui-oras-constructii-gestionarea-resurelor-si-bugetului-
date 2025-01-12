#include "Money.h"

Money::Money(int &amount)
{
	this->amount = 1000;
}

Money::~Money()
{
}

int Money::getMoney()
{
	return amount;
}

bool Money::spendMoney(int cost)
{
    if (amount >= cost) {
        amount -= cost;
        return true;
    }
    return false;
}

bool Money::addMoney(int cost)
{
	if (amount >= 0)
	{
		amount += cost;
		return true;
	}
}


