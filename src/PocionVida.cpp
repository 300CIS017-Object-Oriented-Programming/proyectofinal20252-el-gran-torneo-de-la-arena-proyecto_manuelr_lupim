#include "PocionVida.h"
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

PocionVida::PocionVida(int stock)
    : ObjetoMagico("Pocion de Vida", "Restaura entre 20 y 40 puntos de vida", stock) {}

void PocionVida::usar(Personaje* objetivo) {
    if (!objetivo) return;

    int curacion = 20 + (rand() % 21);
    objetivo->curar(curacion);

    cout << objetivo->getNombre() << " usa Pocion de Vida y recupera "
         << curacion << " puntos de vida." << endl;
}