#include "Guerrero.h"
#include <iostream>
#include <cstdlib> //para el rand
#include <ctime>
using std::string;
using std::cin;
using std::cout;
using std::endl;

//copnstructor y lo mismo que todos los personajes, le añade sus valores.
Guerrero::Guerrero(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Guerrero"), probabilidadCritico(0.2f) {} //usando la herencia, le da los datos de personaje y le dice que el nombre es guerrero, y probabilidad de daño de hasta 20%


//es mét.odo que define cómo pelea un Guerrero.
void Guerrero::realizarAccion(Personaje* objetivo) {       //dos cosas, revisa si el puntero esta incorrecto, y revisa si el objetivo(enemigo) le quedan puntos de vida
    if (!objetivo || !objetivo->estaVivo()) {
        cout << nombre << " no tiene objetivo valido." << endl;   //para que no ataque a personajes que ya estan muertos.
        return;
    }

    int danio = ataque;
    bool critico = (rand() % 100) < (probabilidadCritico * 100);

    if (critico) {
        danio *= 2;
        cout << nombre << " realiza un GOLPE CRITICO" << endl;
    }

    cout << nombre << " ataca a " << objetivo->getNombre()
         << " con su espada. Dano: " << danio << endl;

    objetivo->recibirDanio(danio);

    cout << objetivo->getNombre() << " tiene "
         << objetivo->getVida() << " puntos de vida." << endl;
}