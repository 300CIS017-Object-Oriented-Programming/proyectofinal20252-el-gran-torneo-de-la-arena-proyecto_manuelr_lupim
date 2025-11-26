#include "Arena.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Sanador.h"
#include "Berserker.h"
#include "Lupasos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Arena::Arena(Guild* guild) : guildJugador(guild), turnoActual(1), objetosUsados(0) {}

Arena::~Arena() {
    for (Personaje* oponente : oponentes) {
        delete oponente;
    }
}

void Arena::inicializarOponentes() {
    oponentes.push_back(new Guerrero("Dravos", 5, 100, 22, 12));
    oponentes.push_back(new Mago("Selene", 5, 70, 28, 6));
    oponentes.push_back(new Sanador("Theron", 5, 85, 12, 8));
    oponentes.push_back(new Berserker("Gorak", 5, 105, 26, 11));
    oponentes.push_back(new Lupasos("Ulric", 5, 95, 20, 12));

    cout << "\n=== Oponentes en la Arena ===" << endl;
    for (Personaje* oponente : oponentes) {
        oponente->mostrarInfo();
    }
}
