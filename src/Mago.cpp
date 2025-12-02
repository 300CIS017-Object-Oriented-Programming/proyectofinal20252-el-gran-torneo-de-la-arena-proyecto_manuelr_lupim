#include "Mago.h"
#include <cstdlib>    // genera el rand
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

Mago::Mago(string n, int nv, int v, int a, int d)  // llama al constructor padre
    : Personaje(n, nv, v, a, d, "Mago") {}

void Mago::realizarAccion(Personaje* objetivo) {      //verifica que si este atancando un enemigo y que este tenga vida
    if (!objetivo || !objetivo->estaVivo()) {
        cout << nombre << " no tiene objetivo valido." << endl;
        return;
    }

    int danioExtra = rand() % 15 + 5;   // genera un numero del 0 al 14 y se le suma 5 (daño extra entre 5 y 19)
    int danio = ataque + danioExtra;

    cout << nombre << " lanza un hechizo arcano contra "
         << objetivo->getNombre() << ". Dano magico: " << danio << endl;

    int defensaIgnorada = objetivo->getDefensa() / 2;     // no se usa en el cálculo real, indica la intención: “el mago ignora la mitad de la defensa”.
    int vidaAntes = objetivo->getVida();   // calcula daño al enemigo, restandole el daño a la defensa
    objetivo->recibirDanio(danio);
    int danioReal = vidaAntes - objetivo->getVida();

    cout << objetivo->getNombre() << " recibe " << danioReal
         << " de dano (defensa parcialmente ignorada). Vida restante: "
         << objetivo->getVida() << endl;
}