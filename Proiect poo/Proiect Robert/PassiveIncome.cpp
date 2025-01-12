#include "PassiveIncome.h"


PassiveIncome::PassiveIncome(Money& money, std::vector<House::HouseType>& builtHouses, Happiness& happiness)
    : money(money),builtHouses(builtHouses),happiness(happiness), totalIncome(0), income(0) {}

void PassiveIncome::generateIncome(House::HouseType houseType) {
    int baseIncome = 0;
    switch (houseType) {
    case House::HouseType::Apartment:
        baseIncome = 5;
        break;
    case House::HouseType::Villa:
        baseIncome = 10;
        break;
    case House::HouseType::Cottage:
        baseIncome = 7;
        break;
	case House::HouseType::Park:
		baseIncome = 1;
		break;
    default:
        return;
    }
    double happinessMultiplier = happiness.returnHappiness() / 100.0;  // Assuming happiness.getHappiness() returns a value between 0 and 100

    // Adjust income based on happiness
    int adjustedIncome = static_cast<int>(baseIncome * happinessMultiplier);

    // Deduct the income from the house
    money.spendMoney(-adjustedIncome);
    totalIncome += adjustedIncome;
}

int PassiveIncome::getTotalIncome() const {
    return income;
}

void PassiveIncome::addIncome(House::HouseType houseType)
{
    int income_byhouse;
    switch (houseType) {
    case House::HouseType::Apartment:
        income_byhouse = 5;
        break;
    case House::HouseType::Villa:
        income_byhouse = 10;
        break;
    case House::HouseType::Cottage:
        income_byhouse = 7;
        break;
	case House::HouseType::Park:
		income_byhouse = 1;
		break;
    default:
        return;
    }
    double happinessMultiplier = happiness.returnHappiness() / 100.0;

    // Adjust the income based on happiness
    int adjustedIncome = static_cast<int>(income_byhouse * happinessMultiplier);

    income += adjustedIncome;
}

void PassiveIncome::removeIncome(House::HouseType houseType)
{
    int income_byhouse = 0;
	int money_byhouse = 0;

    switch (houseType) {
    case House::HouseType::Apartment:
        income_byhouse = 5;
		money_byhouse = 100;
        break;
    case House::HouseType::Villa:
        income_byhouse = 10;
		money_byhouse = 250;
        break;
    case House::HouseType::Cottage:
        income_byhouse = 7;
		money_byhouse = 150;
        break;
	case House::HouseType::Park:
		income_byhouse = 1;
		money_byhouse = 125;
    default:
        return;
    }


    double happinessMultiplier = happiness.returnHappiness() / 100.0;
    int adjustedIncome = static_cast<int>(income_byhouse * happinessMultiplier);

    if (income >= income_byhouse) {
        income -= income_byhouse;
		money.addMoney(money_byhouse);
    }
    else {
        income = 0; 
    }
}
