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

void Arena::iniciarCombate() {
    cout << "\n=== COMIENZA EL COMBATE ===" << endl;

    while (true) {
        cout << "\n========================================" << endl;
        cout << "--- TURNO " << turnoActual << " ---" << endl;
        cout << "========================================" << endl;

        // ============= TURNO DE LOS HEROES (JUGADOR) =============
        vector<Personaje*> heroesVivos = guildJugador->getHeroesVivos();

        for (Personaje* heroe : heroesVivos) {
            if (!heroe->estaVivo()) continue;

            // Mostrar estado actual
            cout << "\n>>> Es el turno de: " << heroe->getNombre()
                 << " (" << heroe->getRol() << ")" << endl;
            cout << "   Vida: " << heroe->getVida() << " | Ataque: "
                 << heroe->getAtaque() << " | Defensa: " << heroe->getDefensa() << endl;

            // Mostrar oponentes disponibles
            cout << "\n--- Oponentes disponibles ---" << endl;
            vector<Personaje*> oponentesVivos;
            int index = 1;
            for (Personaje* op : oponentes) {
                if (op->estaVivo()) {
                    cout << index << ". " << op->getNombre() << " (" << op->getRol()
                         << ") - Vida: " << op->getVida() << endl;
                    oponentesVivos.push_back(op);
                    index++;
                }
            }

            if (oponentesVivos.empty()) break;

            // Menu de acciones
            cout << "\n¿Que desea hacer con " << heroe->getNombre() << "?" << endl;
            cout << "1. Atacar a un enemigo" << endl;

            if (heroe->getRol() == "Sanador") {
                cout << "2. Curar a un aliado" << endl;
            }

            // Verificar si el heroe tiene objetos disponibles (simplificado)
            if (!guildJugador->getInventario().empty()) {
                cout << "3. Usar objeto magico" << endl;
            }

            cout << "Opcion: ";
            int accion;
            cin >> accion;

            if (accion == 1) {
                // Atacar
                cout << "Seleccione el objetivo (1-" << oponentesVivos.size() << "): ";
                int objetivo;
                cin >> objetivo;

                if (objetivo >= 1 && objetivo <= oponentesVivos.size()) {
                    Personaje* objetivoSeleccionado = oponentesVivos[objetivo - 1];
                    heroe->realizarAccion(objetivoSeleccionado);

                    if (!objetivoSeleccionado->estaVivo()) {
                        cout << "*** " << objetivoSeleccionado->getNombre()
                             << " ha sido DERROTADO! ***" << endl;
                    }
                } else {
