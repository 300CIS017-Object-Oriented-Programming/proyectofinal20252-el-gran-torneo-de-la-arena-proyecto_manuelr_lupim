#include "Berserker.h"
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

Berserker::Berserker(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Berserker"), modoFuria(false), turnosEnFuria(0) {}   //empieza calmado y no no tiene turnos en furia aun

void Berserker::activarFuria() {
    if (!modoFuria) {              //la furia se activa si no estaba en furia antes
        modoFuria = true;
        turnosEnFuria = 3;         //dura 3 turnos
        ataque = ataque * 1.5; // Aumenta 50% el ataque
        defensa = defensa / 2;  // Reduce 50% la defensa
        cout << "¡" << nombre << " entra en MODO FURIA! Ataque aumentado pero defensa reducida." << endl;
    }
}

void Berserker::desactivarFuria() {
    if (modoFuria) {     //solo funciona si se estaba en furia antes
        modoFuria = false;
        ataque = ataque / 1.5;  //vuelven sus estadisticas base
        defensa = defensa * 2;
        cout << nombre << " sale del modo furia y recupera su defensa." << endl;
    }
}

void Berserker::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) {        //si no hay objetivo o esta muerto no puede atacar
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

    if (danio < 0) danio = 0; //si el daño es menor a 0 siempre cera cero y no un num negativo

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
        turnosEnFuria--;  //se restan cada turno
        if (turnosEnFuria <= 0) {  //cuando llega a cero se desactiva la furia
            desactivarFuria();
        }
    }
}