#include "AmuletoFuria.h"
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

AmuletoFuria::AmuletoFuria(int stock)
    : ObjetoMagico("Amuleto de Furia", "Aumenta el ataque entre 5 y 10 puntos temporalmente", stock) {}

void AmuletoFuria::usar(Personaje* objetivo) {
    if (!objetivo) return;

    int aumento = 5 + (rand() % 6);
    objetivo->setAtaque(objetivo->getAtaque() + aumento);

    cout << objetivo->getNombre() << " usa Amuleto de Furia. Ataque aumentado en "
         << aumento << " puntos." << endl;

}
