#include "DanioElectrico.h"
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

DanioElectrico::DanioElectrico(int stock)
    : ObjetoMagico("Dano Electrico", "Inflige dano electrico directo entre 15 y 30 puntos al enemigo", stock) {}

void DanioElectrico::usar(Personaje* objetivo) {
    if (!objetivo) return;    //Verifica que el puntero no sea nulo. Si es null simplemente no hace nada

    int danio = 15 + (rand() % 16); // Entre 15 y 30
    objetivo->recibirDanio(danio);

    cout << " Dano Electrico activado! " << objetivo->getNombre()
         << " recibe " << danio << " puntos de dano electrico." << endl;

    // Efecto adicional: tiene 30% de probabilidad de "paralizar" (reducir defensa temporalmente)
    if (rand() % 100 < 30) {
        int reduccion = 5;
        objetivo->setDefensa(objetivo->getDefensa() - reduccion);
        cout << "   ¡El shock electrico reduce la defensa de " << objetivo->getNombre()
             << " en " << reduccion << " puntos!" << endl;
    }
}