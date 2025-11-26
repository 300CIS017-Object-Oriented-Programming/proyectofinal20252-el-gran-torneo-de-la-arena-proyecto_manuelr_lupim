#include "arena.h"
#include "personaje.h"
#include <iostream>

void Arena::cargarEquipos(const std::vector<Personaje*> &a, const std::vector<Personaje*> &b) {
    eq1 = a;
    eq2 = b;
}

bool Arena::vivos(const std::vector<Personaje*> &v) {
    for (auto p : v) if (p->estaVivo()) return true;
    return false;
}

void Arena::iniciar() {
    int turno = 1;
    while (vivos(eq1) && vivos(eq2)) {
        for (auto p : eq1) {
            if (!p->estaVivo()) continue;
            for (auto r : eq2) {
                if (r->estaVivo()) {
                    p->atacar(r);
                    break;
                }
            }
        }
        for (auto r : eq2) {
            if (!r->estaVivo()) continue;
            for (auto p : eq1) {
                if (p->estaVivo()) {
                    r->atacar(p);
                    break;
                }
            }
        }
        turno++;
        if (turno > 200) break;
    }
}
