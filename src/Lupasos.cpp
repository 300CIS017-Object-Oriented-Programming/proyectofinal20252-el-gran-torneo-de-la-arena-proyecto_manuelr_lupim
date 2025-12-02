#include "Lupasos.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Lupasos::Lupasos(string n, int nv, int v, int a, int d)
    : Personaje(n, nv, v, a, d, "Lupasos"), formaLobo(false), contadorAtaques(0) {}

void Lupasos::transformar() {
    if (!formaLobo) {  //se transforma si no esta transformado valga la redundancia
        formaLobo = true;
        ataque = ataque + 10; // Mas daño al transformarse +10 por un cierto tiempo
        cout << "Roar ¡" << nombre << " se transforma en LOBO! Su ataque aumenta." << endl;
    }
}

void Lupasos::volverHumano() {
    if (formaLobo) {      //ocurre si esta en modo lobo
        formaLobo = false;
        ataque = ataque - 10; //Cuando deja de ser hombre lobo, disminuye nuevamente su daño -10
        cout << nombre << " vuelve a forma humana." << endl;
    }
}

void Lupasos::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) {
        cout << nombre << " no tiene objetivo valido." << endl;
        return;
    }

    contadorAtaques++;  //cada ataque aumenta el contador para transformarese

    // Cada 3 ataques, se transforma
    if (contadorAtaques % 3 == 0 && !formaLobo) {   //trasforrmacion automatica cada 3 ataques
        transformar();
    }

    int danio = ataque;

    if (formaLobo) {
        // En forma de lobo, tiene probabilidad de ataque multiple
        bool ataqueDoble = (rand() % 100) < 35; // 35% probabilidad de hacer ataque doble

        if (ataqueDoble) {
            cout << "Roar " << nombre << " realiza un ATAQUE DOBLE en forma de lobo" << endl;
            cout << "   Primer zarpazo: ";
            objetivo->recibirDanio(danio);  //ataque completo  o daño cmpleto
            cout << objetivo->getNombre() << " recibe " << danio << " de dano." << endl;

            if (objetivo->estaVivo()) {
                cout << "   Segundo zarpazo: ";
                int danio2 = danio / 2;     //el segundo zarpaso hace la mitad de daño
                objetivo->recibirDanio(danio2);
                cout << objetivo->getNombre() << " recibe " << danio2 << " de dano adicional." << endl;
            }
        } else {
            cout << "Roar " << nombre << " ataca con sus garras de lobo a "
                 << objetivo->getNombre() << ". Dano: " << danio << endl;
            objetivo->recibirDanio(danio);
        }

        // Cada 2 turnos en forma lobo, vuelve a humano
        if (contadorAtaques % 2 == 0) {
            volverHumano();
        }
    } else {
        // En forma humana, ataque normal
        cout << nombre << " ataca a " << objetivo->getNombre()
             << ". Dano: " << danio << endl;
        objetivo->recibirDanio(danio);
    }

    cout << objetivo->getNombre() << " tiene "
         << objetivo->getVida() << " puntos de vida." << endl;
}

