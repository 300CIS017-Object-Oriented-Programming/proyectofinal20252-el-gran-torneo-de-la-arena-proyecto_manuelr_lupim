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
