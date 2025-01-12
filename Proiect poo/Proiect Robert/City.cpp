#include "City.h"

City::City(const string& name, std::vector<House::HouseType>& builtHouses, 
    PassiveIncome& passiveIncome, Money& money,
    Happiness& happiness )
	: name(name), builtHouses(builtHouses), passiveIncome(passiveIncome), money(money), happiness(happiness)
{
}

City::~City()
{
	for (size_t i = 0; i < houses.size(); ++i)
	{
		houses.pop_back();
	}
}

void City::addHouse(const House& house, Money& money)
{
    int cost;
    switch (house.getHouseType()) {
    case House::HouseType::Apartment:
        cost = 200;
		this->happiness.removeHappiness(10);
        break;
    case House::HouseType::Villa:
        cost = 500;
		this->happiness.removeHappiness(20);
        break;
    case House::HouseType::Cottage:
        cost = 300;
		this->happiness.removeHappiness(15);
        break;
    case House::HouseType::Park:
		cost = 250;
		this->happiness.addHappiness(20);
        break;
    default:
        std::cout << "Invalid house type. Cannot add house." << std::endl;
        return;
    }

    if (money.spendMoney(cost)) {
        houses.push_back(house);
        std::cout << "House added: ";
        switch (house.getHouseType()) {
        case House::HouseType::Apartment:
            std::cout << "Apartment";
            break;
        case House::HouseType::Villa:
            std::cout << "Villa";
            break;
        case House::HouseType::Cottage:
            std::cout << "Cottage";
            break;
		case House::HouseType::Park:
			std::cout << "Park";
			break;
        default:
            break;
        }
        std::cout << " owned by " << house.owner << ". Cost: $" << cost << ". Remaining Money: $" << money.getMoney() << std::endl;
    }
    else {
        std::cout << "Not enough money to buy this house. Required: $" << cost << ", Available: $" << money.getMoney() << std::endl;
    }


}

void City::removeHouse(const string& owner)
{
    bool found = false; 
    for (size_t i = 0; i < houses.size(); ++i) {
        if (houses[i].owner == owner) {
            found = true;
 
            House::HouseType type = houses[i].getHouseType();

            // Print removal message
            std::cout << "Removing house: ";
            std::string houseTypeStr;

            switch (type) {
            case House::HouseType::Apartment:
                houseTypeStr = "Apartment";
                break;
            case House::HouseType::Villa:
                houseTypeStr = "Villa";
                break;
            case House::HouseType::Cottage:
                houseTypeStr = "Cottage";
                break;
			case House::HouseType::Park:
				houseTypeStr = "Park";
				break;
            default:
                houseTypeStr = "Unknown House Type";
                break;
            }

            std::cout << houseTypeStr << " owned by " << houses[i].owner << std::endl;

            houses.erase(houses.begin() + i);
   

            auto it = std::find(builtHouses.begin(), builtHouses.end(), type);
            if (it != builtHouses.end()) {
                builtHouses.erase(it);
                this->passiveIncome.removeIncome(type);
            }
			
           

            return;  
        }
    }

    std::cout << "House owned by " << owner << " not found in the city." << std::endl;
}

void City::displayCity() const
{
    if (houses.empty()) {
        cout << "No houses in the city yet!" << endl;
    }
    else {
        cout << "City: " << name << endl;
        for (size_t i = 0; i < houses.size(); ++i) {
            cout << "  " << i + 1 << ". ";
            houses[i].display();
        }
    }
}
