#include "Oras.h"

int main() {
    Oras oras(1000);  

    Constructie casa("Casa", 300);
    Constructie scoala("Scoala", 500);
    Constructie parc("Parc", 200);

    oras.adaugaConstructie(casa);
    oras.adaugaConstructie(scoala);
    oras.adaugaConstructie(parc);

    oras.afiseazaStatus();

    return 0;
}
