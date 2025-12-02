#include "EscudoBendito.h"
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

EscudoBendito::EscudoBendito(int stock)
    : ObjetoMagico("Escudo Bendito", "Aumenta la defensa entre 10 y 20 puntos temporalmente", stock) {}

void EscudoBendito::usar(Personaje* objetivo) {
    if (!objetivo) return;

    int aumento = 10 + (rand() % 11);
    objetivo->setDefensa(objetivo->getDefensa() + aumento);

    cout << objetivo->getNombre() << " usa Escudo Bendito. Defensa aumentada en "
         << aumento << " puntos." << endl;
}