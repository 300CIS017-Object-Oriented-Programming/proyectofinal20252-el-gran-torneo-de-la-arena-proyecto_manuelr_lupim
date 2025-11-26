#include "Tornado.h"
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

Tornado::Tornado(int stock)
    : ObjetoMagico("Tornado", "Invoca un tornado que causa dano variable y puede confundir al enemigo", stock) {}

void Tornado::usar(Personaje* objetivo) {
    if (!objetivo) return;

    int danio = 10 + (rand() % 21); // Entre 10 y 30
    objetivo->recibirDanio(danio);

    cout << "  ¡Tornado invocado! Los vientos furiosos golpean a "
         << objetivo->getNombre() << " causando " << danio << " puntos de dano." << endl;

    // Efecto adicional: 40% probabilidad de reducir ataque temporalmente (confusion)
    if (rand() % 100 < 40) {
        int reduccion = 3 + (rand() % 5); // Reduce entre 3 y 7 puntos
        int ataqueActual = objetivo->getAtaque();
        objetivo->setAtaque(ataqueActual - reduccion);
        cout << "   ¡El tornado confunde a " << objetivo->getNombre()
             << "! Su ataque se reduce en " << reduccion << " puntos." << endl;
    }
}