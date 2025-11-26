#include "Berserker.h"
#include <iostream>
#include <cstdlib>
using std::endl;
using std::cout;

Berserker::Berserker(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Berserker"), modoFuria(false), turnosEnFuria(0) {}

void Berserker::activarFuria() {
    if (!modoFuria) {
        modoFuria = true;
        turnosEnFuria = 3;
        ataque = ataque * 1.5; // Aumenta 50% el ataque
        defensa = defensa / 2;  // Reduce 50% la defensa
        cout << "¡" << nombre << " entra en MODO FURIA! Ataque aumentado pero defensa reducida." << endl;
    }
}