#include "DagaSombria.h"
#include <iostream>
using std::cout;
using std::endl;

DagaSombria::DagaSombria(int stock)
    : ObjetoMagico("Daga Sombria", "Un arma oscura que ignora toda defensa", stock)
{
}

void DagaSombria::usar(Personaje* objetivo) {
    int danio = 50;

    cout << "La Daga Sombria atraviesa toda defensa de "
         << objetivo->getNombre() << "!" << endl;

    objetivo->recibirDanioDirecto(danio);

    cout << objetivo->getNombre()
         << " recibe " << danio << " puntos de dano directo." << endl;
}