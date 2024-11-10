#include "Oras.h"

void Oras::adaugaConstructie(Constructie& c) {
    if (buget >= c.getCost()) {
        constructii.push_back(c);
        buget -= c.getCost();
        cout << "Constructie adaugata: " << c.getNume() << "\n";
    }
    else {
        cout << "Buget insuficient pentru: " << c.getNume() << "\n";
    }
}


void Oras::afiseazaStatus() {
    cout << "Buget ramas: " << buget << "\n";
    cout << "Constructii in oras:\n";
    for (auto& it : constructii) {
        cout << "- " << it.getNume() << "\n";
    }
}