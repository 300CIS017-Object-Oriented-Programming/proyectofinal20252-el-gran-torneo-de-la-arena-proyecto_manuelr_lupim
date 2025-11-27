#include "Berserker.h"
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

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

void Berserker::desactivarFuria() {
    if (modoFuria) {
        modoFuria = false;
        ataque = ataque / 1.5;
        defensa = defensa * 2;
        cout << nombre << " sale del modo furia y recupera su defensa." << endl;
    }
}

void Berserker::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) {
        cout << nombre << " no tiene objetivo valido." << endl;
        return;
    }

    // Si la vida esta baja (menos del 40%), entra en furia
    if (vida < (vidaMaxima * 0.4) && !modoFuria) {
        activarFuria();
    }

    // Realizar ataque
    int danio = ataque;
    int variacion = rand() % 11 - 5; // -5 a +5
    danio += variacion;

    if (danio < 0) danio = 0;

    if (modoFuria) {
        cout << nombre << " ataca con FURIA SALVAJE a " << objetivo->getNombre()
             << "! Dano: " << danio << endl;
    } else {
        cout << nombre << " ataca ferozmente a " << objetivo->getNombre()
             << ". Dano: " << danio << endl;
    }

    objetivo->recibirDanio(danio);

    cout << objetivo->getNombre() << " tiene "
         << objetivo->getVida() << " puntos de vida." << endl;

    // Gestionar turnos de furia
    if (modoFuria) {
        turnosEnFuria--;
        if (turnosEnFuria <= 0) {
            desactivarFuria();
        }
    }
}