#include "src/Personaje.h"
#include "src/Guild.h"
#include "src/Inventario.h"
#include "src/Arena.h"

int main() {
    Guild guild;
    Inventario inventario;

    Heroe* heroePrincipal = nullptr; // es para poder tener al heroe que vas a utilizar
    int puntosJugador = 0;   //son los puntos que se ganan al final de cada ronda para poder subir de nivel.


    // Pre-cargar heroes y enemigos
    guild.inicializarPreCargados();

    // para elegir a tu heroe
    std::cout << "Elige tu heroe principal:\n";
    auto hs = guild.listarHeroes();
    for (auto h : hs) {
        std::cout << h->getId() << ") " << h->getNombre() << " (" << h->getRol() << ")\n";
    }

    int idElegido;
    std::cout << "Ingresa el ID del héroe: ";
    std::cin >> idElegido;

    heroePrincipal = guild.obtenerHeroe(idElegido);

    if (!heroePrincipal) {
        std::cout << "ID invalido. Se asigna el primero automaticamente.\n";
        heroePrincipal = hs[0];
    }

    std::cout << "Tu héroe sera: " << heroePrincipal->getNombre() << "\n\n";

    // Crear prototipos de objetos en el inventario
    inventario.crearTipo("PocionVida", new PocionVida(), 3);
    inventario.crearTipo("AmuletoFuria", new AmuletoFuria(), 2);
    inventario.crearTipo("EscudoBendito", new EscudoBendito(), 2);

    Arena arena(&guild, &inventario, heroePrincipal);

    bool running = true;
    while (running) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1) Listar heroes\n2) Listar inventario\n3) Asignar objeto a heroe\n4) Iniciar combate (demo)\n5) Guardar heroes (JSON)\n6) Cargar/Mostrar heroes desde JSON\n7) Salir\n";
        std::cout << "Seleccione opcion: ";
        int opt;
        if (!(std::cin >> opt)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (opt == 1) {
            auto heroes = guild.listarHeroes();
            std::cout << "Heroes:\n";
            for (Heroe* h : heroes) {
                std::cout << " id: " << h->getId() << " nombre: " << h->getNombre()
                          << " vida: " << h->getVida() << " tipo: " << h->tipo() << "\n";
                h->listarObjetos();
            }
        } else if (opt == 2) {
            inventario.listar();
        } else if (opt == 3) {
            int id; std::string objname;
            std::cout << "Id del heroe: "; std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nombre del objeto a asignar (PocionVida / AmuletoFuria / EscudoBendito): ";
            std::getline(std::cin, objname);
            Heroe* h = guild.obtenerHeroe(id);
            if (!h) { std::cout << "Heroe no encontrado.\n"; continue; }
            inventario.asignarAHeroe(h, objname);
        } else if (opt == 4) {}
    }
}
