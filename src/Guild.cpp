#include "Guild.h"
#include "personaje.h"
#include <iostream>

Guild::~Guild() {
    for (auto p : heroes) delete p;
}

void Guild::agregar(Personaje *p) { heroes.push_back(p); }

void Guild::listar() const {
    for (auto p : heroes)
        std::cout << p->getId() << " - " << p->getNombre() << " vida=" << p->getVida() << "\n";
}

Personaje* Guild::obtenerPorId(int id) const {
    for (auto p : heroes) if (p->getId() == id) return p;
    return nullptr;
}

std::vector<Personaje*>& Guild::getHeroes() { return heroes; }
