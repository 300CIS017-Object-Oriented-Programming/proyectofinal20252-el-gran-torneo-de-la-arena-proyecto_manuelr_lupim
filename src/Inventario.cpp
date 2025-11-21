#include "Inventario.h"
#include "ObjetoMagico.h"
#include "Personaje.h"
#include <iostream>

void Inventario::agregarTipo(const std::string &n, int c) {
    stock[n] += c;
}

bool Inventario::asignar(Personaje *p, const std::string &t) {
    if (!p || stock[t] <= 0) return false;
    ObjetoMagico *obj = new ObjetoMagico(t, 1);
    if (!p->agregarObjeto(obj)) {
        delete obj;
        return false;
    }
    stock[t]--;
    return true;
}

void Inventario::mostrar() const {
    for (auto &kv : stock)
        std::cout << kv.first << ": " << kv.second << "\n";
}