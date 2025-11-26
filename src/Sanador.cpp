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

    cout << nombre << " ataca debilmente a " << objetivo->getNombre() << endl;
    objetivo->recibirDanio(ataque / 2);
}

void Sanador::curarAliado(vector<Personaje*>& aliados) {
    Personaje* objetivo = nullptr;
    int menorVida = 999999;

    for (Personaje* aliado : aliados) {
        if (aliado->estaVivo() && aliado != this && aliado->getVida() < menorVida) {
            objetivo = aliado;
            menorVida = aliado->getVida();
        }
    }

    if (objetivo) {
        int efectividad = 60 + (rand() % 41);
        int curacion = (30 * efectividad) / 100;

        cout << nombre << " canaliza energia curativa. Efectividad: "
             << efectividad << "%. ";

        objetivo->curar(curacion);
        cout << objetivo->getNombre() << " recupera " << curacion
             << " puntos de vida." << endl;
    } else {
        cout << nombre << " no encuentra aliados para curar." << endl;
    }
}