#include "Heroe.h"
#include <iostream>

/* Heroe base */
Heroe::Heroe(int id, const std::string &nombre, int nivel, int vida, int ataque, int defensa)
: Personaje(id, nombre, nivel, vida, ataque, defensa) {}

Heroe::~Heroe() {
    // liberar objetos asignados al héroe
    for (ObjetoMagico* o : objetos) delete o;
    objetos.clear();
}

bool Heroe::asignarObjeto(ObjetoMagico* obj) {
    if ((int)objetos.size() >= 2) return false;
    objetos.push_back(obj);
    return true;
}

bool Heroe::retirarObjeto(int index) {
    if (index < 0 || index >= (int)objetos.size()) return false;
    delete objetos[index];
    objetos.erase(objetos.begin() + index);
    return true;
}

void Heroe::usarObjeto(int index, Personaje *objetivo) {
    if (index < 0 || index >= (int)objetos.size()) return;
    ObjetoMagico* o = objetos[index];
    if (o) {
        o->aplicar(objetivo);
        // suponer que los objetos tienen 1 uso y se consumen
        delete o;
    }
    objetos.erase(objetos.begin() + index);
}

void Heroe::listarObjetos() const {
    std::cout << "Objetos de " << nombre << ": ";
    if (objetos.empty()) {
        std::cout << "ninguno\n";
        return;
    }
    std::cout << "\n";
    for (size_t i = 0; i < objetos.size(); ++i) {
        std::cout << "  [" << i << "] " << objetos[i]->getNombre() << "\n";
    }
}

void Heroe::atacar(Personaje *objetivo) {
    Personaje::atacar(objetivo);
}

/* Guerrero */
Guerrero::Guerrero(int id, const std::string &nombre) : Heroe(id, nombre, 1, 120, 25, 5) {}
void Guerrero::atacar(Personaje *objetivo) {
    // golpe fuerte: 120% de ataque
    int dano = static_cast<int>(ataque * 1.2);
    objetivo->recibirDanio(dano);
    std::cout << nombre << " (Guerrero) golpea por " << dano << " de daño.\n";
}

/* Mago */
Mago::Mago(int id, const std::string &nombre) : Heroe(id, nombre, 1, 80, 30, 2) {}
void Mago::atacar(Personaje *objetivo) {
    // hechizo: daño fijo + ataque
    int dano = ataque + 10;
    objetivo->recibirDanio(dano);
    std::cout << nombre << " (Mago) lanza hechizo por " << dano << " de daño.\n";
}

/* Sanador */
Sanador::Sanador(int id, const std::string &nombre) : Heroe(id, nombre, 1, 90, 10, 3) {}
void Sanador::curarAliado(Heroe *aliado) {
    if (!aliado) return;
    aliado->setVida(aliado->getVida() + 25);
    std::cout << nombre << " (Sanador) cura a " << aliado->getNombre() << " por 25.\n";
}