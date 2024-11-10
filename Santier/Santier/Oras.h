#pragma once // Previne includerea multipla a acestui header
#include "Constructie.h" 

// Clasa Oras, care mosteneste clasa Constructie in mod public
class Oras : public Constructie {
public:
    // Constructorul clasei Oras care initializeaza bugetul orasului
    Oras(int buget_initial) : buget(buget_initial) {}

    // Metoda care adauga o constructie in oras
    void adaugaConstructie(Constructie& c);

    // Metoda care afiseaza statusul orasului, inclusiv bugetul si constructiile adaugate
    void afiseazaStatus();

private:
    int buget; // Bugetul orasului
    vector<Constructie> constructii; // Lista de constructii adaugate in oras
};
