#include "House.h"

House::House() : owner(""), houseType(HouseType::Invalid) {}

House::House(const string& owner, HouseType houseType)
	: owner(owner), houseType(houseType)
{

}

House::~House()
{
}

void House::display() const
{
    std::cout << "House owned by " << owner << " Type: ";
    switch (houseType) {
    case HouseType::Apartment:
        std::cout << "Apartment";
        break;
    case HouseType::Villa:
        std::cout << "Villa";
        break;
    case HouseType::Cottage:
        std::cout << "Cottage";
        break;
    case HouseType::Park:
		std::cout << "Park";
		break;
    default:
        std::cout << "Invalid";
        break;
    }
    std::cout << std::endl;
}

void House::createHouse()
{
    std::cout << "Enter the name of the house owner: ";
    std::getline(std::cin, owner);

    houseType = chooseHouseType();
 
}

House::HouseType House::chooseHouseType() {
    std::cout << "Choose the type of house:\n"
        << "1. Apartment = 200 dollars\n"
        << "2. Villa = 500 dollars\n"
        << "3. Cottage = 300 dollars\n"
		<< "4. Park = 250 dollars\n"
        << "Enter your choice (1-4): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Clear the newline character from input

    switch (choice) {
    case 1:
        return HouseType::Apartment;
    case 2:
        return HouseType::Villa;
    case 3:
        return HouseType::Cottage;
    case 4:
		return HouseType::Park;
    default:
        std::cout << "Invalid choice. Defaulting to Invalid." << std::endl;
        return HouseType::Invalid;
    }
}


House::HouseType House::getHouseType() const {
    return houseType;
}