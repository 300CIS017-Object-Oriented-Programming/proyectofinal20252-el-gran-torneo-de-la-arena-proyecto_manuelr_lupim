#include "Sanador.h"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::cin;

Sanador::Sanador(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Sanador") {}

void Sanador::realizarAccion(Personaje* objetivo) {             // se utiliza para que realice la accion a un objetivo
    if (!objetivo) {
        cout << nombre << " no tiene objetivo valido." << endl;
        return;
    }

    cout << nombre << " ataca debilmente a " << objetivo->getNombre() << endl;
    objetivo->recibirDanio(ataque / 2);              //el ataque de el sanador es la mitad de eficaz con respecto a su ataque base
}

void Sanador::curarAliado(vector<Personaje*>& aliados) {
    Personaje* objetivo = nullptr;  // se guarda como puntero al aliado a curar
    int menorVida = 999999;         // sirve para asegurar que cualquier aliado vivo este por debajo de ese numero

    for (Personaje* aliado : aliados) {
        if (aliado->estaVivo() && aliado != this && aliado->getVida() < menorVida) {
            objetivo = aliado;
            menorVida = aliado->getVida();
        }
    }

    if (objetivo) {
        int efectividad = 60 + (rand() % 41);  //la efectividad genera un numero entre 0 y 40 y este se suma con 60 dando un numero entre 60 y 100
        int curacion = (30 * efectividad) / 100;  // con la efectividad se puede saber la curacion que de base es 30 pero puede bajar su efectividad

        cout << nombre << " canaliza energia curativa. Efectividad: "
             << efectividad << "%. ";

        objetivo->curar(curacion);        //con el metodo curar nos aseguramos que respete la 'VidaMAX'
        cout << objetivo->getNombre() << " recupera " << curacion
             << " puntos de vida." << endl;
    } else {
        cout << nombre << " no encuentra aliados para curar." << endl;
    }
}