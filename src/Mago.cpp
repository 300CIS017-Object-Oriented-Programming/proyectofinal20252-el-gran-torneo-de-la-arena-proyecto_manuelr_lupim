#include "Mago.h"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::cin;

Mago::Mago(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Mago") {}

void Mago::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) {
        cout << nombre << " no tiene objetivo valido." << endl;
        return;
    }