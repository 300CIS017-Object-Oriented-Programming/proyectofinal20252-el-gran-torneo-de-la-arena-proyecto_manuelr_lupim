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

    int danioExtra = rand() % 15 + 5;
    int danio = ataque + danioExtra;

    cout << nombre << " lanza un hechizo arcano contra "
         << objetivo->getNombre() << ". Dano magico: " << danio << endl;

    int defensaIgnorada = objetivo->getDefensa() / 2;
    int vidaAntes = objetivo->getVida();
    objetivo->recibirDanio(danio);
    int danioReal = vidaAntes - objetivo->getVida();

    cout << objetivo->getNombre() << " recibe " << danioReal
         << " de dano (defensa parcialmente ignorada). Vida restante: "
         << objetivo->getVida() << endl;
}