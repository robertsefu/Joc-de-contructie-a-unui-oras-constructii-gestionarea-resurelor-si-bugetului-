#include "Happiness.h"

Happiness::Happiness(int& happines)
	: happinesTotal(happines)
{

}

Happiness::~Happiness()
{

}

void Happiness::addHappiness(int happines)
{
	happinesTotal += happines;
}

void Happiness::removeHappiness(int happines)
{
	happinesTotal -= happines;
}

int Happiness::returnHappiness()
{
	return happinesTotal;
}
