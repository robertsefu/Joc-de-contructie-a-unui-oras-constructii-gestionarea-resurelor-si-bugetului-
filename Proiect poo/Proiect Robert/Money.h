#ifndef MONEY_H
#define MONEY_H

#include <iostream>
using namespace std;
class Money
{
public:
	int amount;

	Money(int &amount);
	virtual ~Money();

	int getMoney();
	bool spendMoney(int cost);
	bool addMoney(int cost);
};

#endif