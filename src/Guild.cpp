#include "guild.h"
#include "Guild.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Sanador.h"
#include "Berserker.h"
#include "Lupasos.h"
#include "PocionVida.h"
#include "AmuletoFuria.h"
#include "EscudoBendito.h"
#include "DanioElectrico.h"
#include "Tornado.h"
#include <iostream>
#include <fstream>
#include "DagaSombria.h"
#include "JSON.hpp"

using std::cin;
using std::cout;
using std::endl;

Guild::Guild(string nombre) : nombreGuild(nombre), contadorId(1) {}

Guild::~Guild() {
    for (auto& par : heroes) {
        delete par.second;
    }
    for (ObjetoMagico* obj : inventario) {
        delete obj;
    }
}

void Guild::inicializarHeroes() {
    agregarHeroe(new Guerrero("Arthos", 5, 120, 25, 15));
    agregarHeroe(new Mago("Lyra", 5, 80, 30, 8));
    agregarHeroe(new Sanador("Elara", 5, 90, 15, 10));
    agregarHeroe(new Berserker("Ragnar", 5, 110, 28, 12));
    agregarHeroe(new Lupasos("Fenrir", 5, 100, 22, 13));

    agregarObjeto(new PocionVida(3));
    agregarObjeto(new AmuletoFuria(2));
    agregarObjeto(new EscudoBendito(2));
    agregarObjeto(new DanioElectrico(2));
    agregarObjeto(new Tornado(2));
    agregarObjeto(new DagaSombria(3));
}

void Guild::agregarHeroe(Personaje* heroe) {
    if (!heroe) return;

    string clave = heroe->getNombre();
    if (heroes.find(clave) == heroes.end()) {
        heroes[clave] = heroe;
        cout << "Heroe " << heroe->getNombre() << " agregado a " << nombreGuild << endl;
    } else {
        cout << "Ya existe un heroe con ese nombre." << endl;
        delete heroe;
    }
}

//VER QUE ES
void Guild::eliminarHeroe(string nombre) {
    auto it = heroes.find(nombre);
    if (it != heroes.end()) {
        delete it->second;
        heroes.erase(it);
        cout << "Heroe " << nombre << " eliminado." << endl;
    } else {
        cout << "Heroe no encontrado." << endl;
    }
}

Personaje* Guild::buscarHeroe(string nombre) {
    auto it = heroes.find(nombre);
    return (it != heroes.end()) ? it->second : nullptr;
}

void Guild::listarHeroes() const {
    cout << "\n=== Heroes de " << nombreGuild << " ===" << endl;
    if (heroes.empty()) {
        cout << "No hay heroes en la guild." << endl;
        return;
    }

    for (const auto& par : heroes) {
        par.second->mostrarInfo();
    }
}

void Guild::agregarObjeto(ObjetoMagico* objeto) {
    if (objeto) {
        inventario.push_back(objeto);
    }
}

void Guild::listarInventario() const {
    cout << "\n=== Inventario de Objetos Magicos ===" << endl;
    if (inventario.empty()) {
        cout << "No hay objetos en el inventario." << endl;
        return;
    }

    for (const ObjetoMagico* obj : inventario) {
        obj->mostrarInfo();
    }
}

vector<Personaje*> Guild::getHeroesVivos() const {
    vector<Personaje*> vivos;
    for (const auto& par : heroes) {
        if (par.second->estaVivo()) {
            vivos.push_back(par.second);
        }
    }
    return vivos;
}

vector<ObjetoMagico*>& Guild::getInventario() {
    return inventario;
}

string Guild::getNombre() const {
    return nombreGuild;
}
void Guild::guardarHeroesJSON(const std::string& filename) const {
    try {
        nlohmann::json j;
        j["guild"] = nombreGuild;
        j["heroes"] = nlohmann::json::array();

        for (const auto& par : heroes) {
            const Personaje* h = par.second;
            nlohmann::json hj;
            hj["tipo"] = h->getRol();
            hj["nombre"] = h->getNombre();
            hj["nivel"] = h->getNivel();
            hj["vida"] = h->getVida();
            hj["ataque"] = h->getAtaque();
            hj["defensa"] = h->getDefensa();
            j["heroes"].push_back(hj);
        }

        std::ofstream ofs(filename);
        if (!ofs) {
            std::cout << "Error: no se pudo abrir el archivo para escribir: " << filename << std::endl;
            return;
        }
        ofs << j.dump(4); // identado 4 espacios
        ofs.close();

        std::cout << "Heroes guardados correctamente en: " << filename << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Excepcion al guardar JSON: " << e.what() << std::endl;
    }
}
//Para guardar los personajes en JSON
void Guild::cargarHeroesDesdeJSON(const std::string& filename) {
    try {
        std::ifstream ifs(filename);
        if (!ifs) {
            std::cout << "Error: no se pudo abrir el archivo para leer: " << filename << std::endl;
            return;
        }

        nlohmann::json j;
        ifs >> j;
        ifs.close();

        if (!j.contains("heroes")) {
            std::cout << "Archivo JSON no tiene 'heroes'." << std::endl;
            return;
        }

        // Iterar y crear personajes según el tipo
        for (const auto& hj : j["heroes"]) {
            std::string tipo = hj.value("tipo", "Guerrero");
            std::string nombre = hj.value("nombre", "SinNombre");
            int nivel = hj.value("nivel", 1);
            int vida = hj.value("vida", 100);
            int ataque = hj.value("ataque", 10);
            int defensa = hj.value("defensa", 5);

            // Evitar duplicados por nombre
            if (buscarHeroe(nombre)) {
                std::cout << "Ya existe el heroe '" << nombre << "'. Se omite." << std::endl;
                continue;
            }

            Personaje* nuevo = nullptr;
            if (tipo == "Guerrero") {
                nuevo = new Guerrero(nombre, nivel, vida, ataque, defensa);
            } else if (tipo == "Mago") {
                nuevo = new Mago(nombre, nivel, vida, ataque, defensa);
            } else if (tipo == "Sanador") {
                nuevo = new Sanador(nombre, nivel, vida, ataque, defensa);
            } else if (tipo == "Berserker") {
                nuevo = new Berserker(nombre, nivel, vida, ataque, defensa);
            } else if (tipo == "Lupasos") {
                nuevo = new Lupasos(nombre, nivel, vida, ataque, defensa);
            } else {
                // Tipo desconocido: crear Guerrero por defecto
                nuevo = new Guerrero(nombre, nivel, vida, ataque, defensa);
            }

            if (nuevo) {
                agregarHeroe(nuevo);
            }
        }

        std::cout << "Carga JSON completada. Lista de heroes cargados/actuales:" << std::endl;
        listarHeroes();

    } catch (const std::exception& e) {
        std::cout << "Excepcion al cargar JSON: " << e.what() << std::endl;
    }
}