#include "guerrero.h"
#include "Guerrero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::string;
using std::cin;
using std::cout;
using std::endl;

Guerrero::Guerrero(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Guerrero"), probabilidadCritico(0.2f) {}

void Guerrero::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) {
        cout << nombre << " no tiene objetivo valido." << endl;
        return;
    }

    int danio = ataque;
    bool critico = (rand() % 100) < (probabilidadCritico * 100);

    if (critico) {
        danio *= 2;
        cout << nombre << " realiza un GOLPE CRITICO" << endl;
    }

    cout << nombre << " ataca a " << objetivo->getNombre()
         << " con su espada. Dano: " << danio << endl;

    objetivo->recibirDanio(danio);

    cout << objetivo->getNombre() << " tiene "
         << objetivo->getVida() << " puntos de vida." << endl;
}