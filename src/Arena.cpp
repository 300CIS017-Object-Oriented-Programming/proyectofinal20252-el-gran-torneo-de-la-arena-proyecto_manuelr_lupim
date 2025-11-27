#include "Arena.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Sanador.h"
#include "Berserker.h"
#include "Lupasos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

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
            cout << "\nQue desea hacer con " << heroe->getNombre() << "?" << endl;
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
                    cout << "Objetivo invalido. Se pierde el turno." << endl;
                }

            } else if (accion == 2 && heroe->getRol() == "Sanador") {
                // Curar aliado
                Sanador* sanador = dynamic_cast<Sanador*>(heroe);
                if (sanador) {
                    cout << "\n--- Aliados disponibles ---" << endl;
                    vector<Personaje*> heroesParaCurar;
                    int idx = 1;
                    for (Personaje* h : heroesVivos) {
                        if (h->estaVivo() && h != heroe) {
                            cout << idx << ". " << h->getNombre()
                                 << " - Vida: " << h->getVida() << endl;
                            heroesParaCurar.push_back(h);
                            idx++;
                        }
                    }

                    if (heroesParaCurar.empty()) {
                        cout << "No hay aliados para curar. Ataque normal." << endl;
                        if (!oponentesVivos.empty()) {
                            heroe->realizarAccion(oponentesVivos[0]);
                        }
                    } else {
                        cout << "Seleccione a quien curar (1-" << heroesParaCurar.size() << "): ";
                        int aliado;
                        cin >> aliado;

                        if (aliado >= 1 && aliado <= heroesParaCurar.size()) {
                            vector<Personaje*> temp;
                            temp.push_back(heroesParaCurar[aliado - 1]);
                            sanador->curarAliado(temp);
                        } else {
                            cout << "Opcion invalida." << endl;
                        }
                    }
                }

            } else if (accion == 3 && !guildJugador->getInventario().empty()) {
                // Usar objeto
                cout << "\n--- Objetos disponibles ---" << endl;
                vector<ObjetoMagico*>& inventario = guildJugador->getInventario();
                int idx = 1;
                for (ObjetoMagico* obj : inventario) {
                    if (obj->getStock() > 0) {
                        cout << idx << ". " << obj->getNombre()
                             << " (Stock: " << obj->getStock() << ")" << endl;
                        idx++;
                    }
                }

                                cout << "Seleccione objeto (0 para cancelar): ";
                int objIdx;
                cin >> objIdx;

                if (objIdx > 0 && objIdx <= inventario.size()) {
                    ObjetoMagico* objSeleccionado = inventario[objIdx - 1];

                    if (objSeleccionado->getStock() > 0) {
                        // Determinar si el objeto es ofensivo o defensivo
                        string nombreObj = objSeleccionado->getNombre();

                        if (nombreObj == "Pocion de Vida" || nombreObj == "Amuleto de Furia"
                            || nombreObj == "Escudo Bendito") {
                            // Usar en el mismo heroe
                            objSeleccionado->usar(heroe);
                            objSeleccionado->decrementarStock();
                            objetosUsados++;
                        } else {
                            // Objetos ofensivos: seleccionar enemigo
                            cout << "Seleccione objetivo enemigo (1-" << oponentesVivos.size() << "): ";
                            int targetIdx;
                            cin >> targetIdx;

                            if (targetIdx >= 1 && targetIdx <= oponentesVivos.size()) {
                                objSeleccionado->usar(oponentesVivos[targetIdx - 1]);
                                objSeleccionado->decrementarStock();
                                objetosUsados++;
                            }
                        }
                    } else {
                        cout << "No hay stock de ese objeto." << endl;
                    }
                } else {
                    cout << "Accion cancelada." << endl;
                }

            } else {
                cout << "Opcion invalida. Se pierde el turno." << endl;
            }

            cout << "\nPresione ENTER para continuar...";
            cin.ignore();
            cin.get();
        }

        if (equipoEliminado(oponentes)) {
            mostrarResumen(guildJugador->getNombre());
            break;
        }

        // ============= TURNO DE LOS OPONENTES (IA) =============
        cout << "\n\n>>> TURNO DE LOS OPONENTES <<<" << endl;

        for (Personaje* oponente : oponentes) {
            if (!oponente->estaVivo()) continue;

            vector<Personaje*> heroesVivos2 = guildJugador->getHeroesVivos();
            if (heroesVivos2.empty()) break;

            // IA: selecciona objetivo aleatorio
            Personaje* objetivo = heroesVivos2[rand() % heroesVivos2.size()];

            if (oponente->getRol() == "Sanador" && rand() % 3 == 0) {
                Sanador* sanador = dynamic_cast<Sanador*>(oponente);
                if (sanador) {
                    vector<Personaje*> oponentesVivos;
                    for (Personaje* op : oponentes) {
                        if (op->estaVivo()) oponentesVivos.push_back(op);
                    }
                    sanador->curarAliado(oponentesVivos);
                }
            } else {
                oponente->realizarAccion(objetivo);
            }

            if (!objetivo->estaVivo()) {
                cout << "*** " << objetivo->getNombre() << " ha sido DERROTADO! ***" << endl;
            }
        }

        if (equipoEliminado(guildJugador->getHeroesVivos())) {
            mostrarResumen("Equipo Oponente");
            break;
        }

        turnoActual++;

        cout << "\nPresione ENTER para continuar al siguiente turno...";
        cin.ignore();
        cin.get();
    }
}

bool Arena::equipoEliminado(const vector<Personaje*>& equipo) const {
    for (Personaje* p : equipo) {
        if (p->estaVivo()) return false;
    }
    return true;
}

void Arena::mostrarResumen(const string& ganador) const {
    cout << "\n========================================" << endl;
    cout << "=== FIN DEL COMBATE ===" << endl;
    cout << "========================================" << endl;
    cout << " Equipo ganador: " << ganador << endl;
    cout << "  Duracion: " << turnoActual << " turnos" << endl;
    cout << " Objetos usados: " << objetosUsados << endl;

    if (ganador == guildJugador->getNombre()) {
        cout << "\n Heroes supervivientes:" << endl;
        vector<Personaje*> supervivientes = guildJugador->getHeroesVivos();
        for (Personaje* h : supervivientes) {
            cout << "  Batallaa  " << h->getNombre() << " - Vida restante: "
                 << h->getVida() << endl;
        }
        cout << "\n¡Victoria para " << guildJugador->getNombre() << "!" << endl;
    } else {
        cout << "\n Derrota... Todos los heroes han caido." << endl;
    }
    cout << "========================================" << endl;
}