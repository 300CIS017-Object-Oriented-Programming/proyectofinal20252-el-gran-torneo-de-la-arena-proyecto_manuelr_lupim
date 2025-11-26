#include "guerrero.h"
#include "Guerrero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::string;
using std::cout;
using std::cin;
using std::endl;

Guerrero::Guerrero(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Guerrero"), probabilidadCritico(0.2f) {}

void Guerrero::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) {
        cout << nombre << " no tiene objetivo valido." << endl;
        return;
    }

