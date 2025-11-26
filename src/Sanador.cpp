#include "Sanador.h"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::cin;

Sanador::Sanador(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Sanador") {}

void Sanador::realizarAccion(Personaje* objetivo) {
    if (!objetivo) {
        cout << nombre << " no tiene objetivo valido." << endl;
        return;
    }