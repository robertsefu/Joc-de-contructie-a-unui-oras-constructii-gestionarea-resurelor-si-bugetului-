#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <string>
#include "Money.h"
using namespace std;

class House
{
public:
    std::string owner;

    enum class HouseType {
        Apartment,
        Villa,
        Cottage,
		Park,
        Invalid,
    };

    House();
    House(const string& owner, HouseType houseType);
    virtual ~House();

    void display() const;
    void createHouse();

    HouseType getHouseType() const;

private:

    HouseType houseType;

    static HouseType chooseHouseType();

};

#endif // HOUSE_H

