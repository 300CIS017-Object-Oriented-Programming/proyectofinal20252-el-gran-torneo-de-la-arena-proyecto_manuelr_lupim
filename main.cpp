#include <iostream>
#include <cstdlib>
#include <ctime>
#include "src/Guild.h"
#include "src/Arena.h"
#include "src/Guerrero.h"
#include "src/Mago.h"
#include "src/Sanador.h"
#include "src/Berserker.h"
#include "src/Lupasos.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void mostrarMenu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Ver heroes de la Guild" << endl;
    cout << "2. Agregar nuevo heroe" << endl;
    cout << "3. Eliminar heroe" << endl;
    cout << "4. Ver inventario" << endl;
    cout << "5. Iniciar combate en la Arena" << endl;
    cout << "6. Guardar heroes (JSON)" << endl;
    cout << "7. Cargar/Mostrar heroes desde JSON" << endl;
    cout << "8. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    srand(time(0));

    cout << "=== BIENVENIDO A LYRENHOLD ===" << endl;
    cout << "Gran Torneo de la Arena" << endl;

    Guild* miGuild = new Guild("Guardianes del Alba");
    miGuild->inicializarHeroes();

    cout << "\nGuild creada exitosamente." << endl;
    miGuild->listarHeroes();

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
                miGuild->listarHeroes();
                break;

            case 2: {
                cout << "\nTipo de heroe:" << endl;
                cout << "1-Guerrero, 2-Mago, 3-Sanador, 4-Berserker, 5-Lupasos: ";
                int tipo;
                cin >> tipo;
                cin.ignore();

                cout << "Nombre: ";
                string nombre;
                getline(cin, nombre);

                Personaje* nuevoHeroe = nullptr;
                if (tipo == 1) {
                    nuevoHeroe = new Guerrero(nombre, 5, 120, 25, 15);
                } else if (tipo == 2) {
                    nuevoHeroe = new Mago(nombre, 5, 80, 30, 8);
                } else if (tipo == 3) {
                    nuevoHeroe = new Sanador(nombre, 5, 90, 15, 10);
                } else if (tipo == 4) {
                    nuevoHeroe = new Berserker(nombre, 5, 110, 28, 12);
                } else if (tipo == 5) {
                    nuevoHeroe = new Lupasos(nombre, 5, 100, 22, 13);
                }

                if (nuevoHeroe) {
                    miGuild->agregarHeroe(nuevoHeroe);
                }
                break;
            }

            case 3: {
                cout << "Nombre del heroe a eliminar: ";
                string nombre;
                getline(cin, nombre);
                miGuild->eliminarHeroe(nombre);
                break;
            }

            case 4:
                miGuild->listarInventario();
                break;

            case 5: {
                vector<Personaje*> heroesVivos = miGuild->getHeroesVivos();
                if (heroesVivos.empty()) {
                    cout << "No hay heroes vivos para combatir." << endl;
                    break;
                }

                Arena* arena = new Arena(miGuild);
                arena->inicializarOponentes();
                arena->iniciarCombate();
                delete arena;
                break;
            }
