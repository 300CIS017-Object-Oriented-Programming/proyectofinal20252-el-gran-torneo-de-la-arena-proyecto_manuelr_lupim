#include "DagaSombria.h"
#include <iostream>
using std::cout;
using std::endl;

DagaSombria::DagaSombria(int stock)
    : ObjetoMagico("Daga Sombria", "Un arma oscura que ignora toda defensa", stock) { //nombre, descripcion y stock
}

void DagaSombria::usar(Personaje* objetivo) {
    int danio = 50;

    cout << "La Daga Sombria atraviesa toda defensa de "
         << objetivo->getNombre() << "!" << endl;

    objetivo->recibirDanioDirecto(danio);    //Llama al met.odo recibirDanioDirecto del Personaje objetivo, pasando danio (50).

    cout << objetivo->getNombre()
         << " recibe " << danio << " puntos de dano directo." << endl;
}

// recibirDanioDirecto(danio); lo que resta 50 puntos a su vida ignorando su defensa. Se imprime la cantidad de daño aplicada.
