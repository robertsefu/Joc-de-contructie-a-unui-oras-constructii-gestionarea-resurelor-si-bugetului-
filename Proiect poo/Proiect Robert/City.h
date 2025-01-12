#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <vector>
#include "House.h"
#include "Money.h"
#include "PassiveIncome.h"
#include "Happiness.h"

using namespace std;

class City
{
private:
    string name;
    vector<House> houses;
    std::vector<House::HouseType>& builtHouses;
	PassiveIncome& passiveIncome;
	Money& money;
	Happiness& happiness;

public:
    City(const string& name, std::vector<House::HouseType>& builtHouses,
        PassiveIncome& passiveIncome,Money& money,
        Happiness& happiness);
	virtual ~City();
    void addHouse(const House& house, Money& money);
	void removeHouse(const string& owner);

    void displayCity() const;

};

#endif // CITY_H
