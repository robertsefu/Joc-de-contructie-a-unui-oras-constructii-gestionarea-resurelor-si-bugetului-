#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

#include "House.h"
#include "City.h"
#include "Money.h"
#include "PassiveIncome.h"
#include "Happiness.h"

using namespace std;



// Main game loop
int main() {
    cout << "Welcome to City Builder! In this game, you will manage a growing city,\nbuild different types of houses, and earn passive income over time.\nThe goal is to expand your city and generate as much income as possible!" << endl <<endl;
	system("pause");
    cout << "Please enter the name of your city: ";
    string cityName;
    getline(cin, cityName);

	int initialMoney;
    int initialHappiness = 100;
    string owner;
    vector<House::HouseType> builtHouses; 

    Money money(initialMoney);
	Happiness happiness(initialHappiness);
	PassiveIncome passiveIncome(money,builtHouses, happiness);
    City city(cityName, builtHouses, passiveIncome, money, happiness);


    time_t lastTime = time(0); 
    time_t currentTime;        

    int choice;

    while (true) {
		system("cls"); 
        cout << cityName << "'s city" << endl <<endl;
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Build a new house" << endl;
        cout << "2. Remove a house" << endl;
        cout << "3. View city" << endl;
        cout << "4. Money and Happines" << endl;
        cout << "5. Rules of the game "<< endl;
		cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: {
            House newHouse;
            newHouse.createHouse(); 

                city.addHouse(newHouse, money);
                builtHouses.push_back(newHouse.getHouseType());
				passiveIncome.addIncome(newHouse.getHouseType());
            
            system("pause");
            break;
        }
        case 2:
            city.displayCity();
            cout << "Enter the name of the house owner you want to remove: ";
            cin.ignore();  
            getline(cin, owner);  
            city.removeHouse(owner);  
            system("pause");
            break;

        case 3:
            city.displayCity();
			system("pause"); 
            break;

        case 4:
            cout << "Money: " << money.getMoney() << endl;
            cout << "Passive Income: " << passiveIncome.getTotalIncome() << endl;
			cout << "Happiness: " << happiness.returnHappiness() << endl;
            system("pause");
            break;
         

		case 5:
			system("cls");

			cout << "Rules of the game: " << endl;
			cout << "When you start the game you begin with an initial amount of money which is set to 1000" << endl <<endl;
			cout << "Building Houses:" << endl;
			cout << "Choose the option to build a new house and select the type of house you want to build." << endl;
			cout << "Apartments, Villas or Cottages" << endl;
			cout << "Choose the number of rooms for the house. A valid number of rooms is required (greater than 0)." << endl;
			cout << "Once built, the house will start generating passive income based on its type." << endl <<endl;
			cout << "Managing Money:" << endl;
			cout << "You need money to build houses, so make sure to keep track of your balance!" << endl;
			cout << "Each house will provide you with a source of passive income, but you must wait for 3 seconds (in real-time) after each income cycle." << endl;
			cout << "Apartments provide 5 dollars, Villas 10 dollars and Cottages 7 dollars" << endl << endl;
			cout << "If you run out of money, you won’t be able to build any more houses until you have earned more passive income." << endl << endl;
			cout << "Viewing Your City:" << endl;
			cout << "You can view a list of all the houses in your city at any time. This will display the house type, owner, and number of rooms for each house." << endl;
			system("pause");
			break;
			
        case 6:
            cout << "Exiting the game..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        currentTime = time(0); 
        if (difftime(currentTime, lastTime) >= 3) { 
            for (const auto& houseType : builtHouses) {
                passiveIncome.generateIncome(houseType); 
            }
            lastTime = currentTime;
        }

    }

    return 0;
}
