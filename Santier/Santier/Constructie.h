#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Constructie {
public:
    // Constructor implicit permite compilatorului sa creeze obiecte de tip Constructie chiar si fara parametri
    Constructie() : nume("Necunoscut"), cost(0) {}

    // Constructor cu parametri
    Constructie(string nume, int cost) : nume(nume), cost(cost) {}

    int getCost(); // returneaza costul unei constructii
    string getNume(); // returneaza tipul de constructie (casa, scoala, bloc, parc, vila, ...)
private:
    string nume;
    int cost;
};
