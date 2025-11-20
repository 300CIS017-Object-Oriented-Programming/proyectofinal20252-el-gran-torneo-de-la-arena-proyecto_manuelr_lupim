#include "Personaje.h"
#include "ObjetoMagico.h"
#include <iostream>

Personaje::Personaje(int id_, const std::string &n, int v, int a, const std::string &t)
: id(id_), nombre(n), vida(v), ataque(a), tipo(t) {}

Personaje::~Personaje() {
    for (auto o : objetos) delete o;
}

int Personaje::getId() const { return id; }
const std::string& Personaje::getNombre() const { return nombre; }
int Personaje::getVida() const { return vida; }
bool Personaje::estaVivo() const { return vida > 0; }

void Personaje::atacar(Personaje *objetivo) {
    if (!estaVivo() || !objetivo || !objetivo->estaVivo()) return;
    objetivo->vida -= ataque;
    if (objetivo->vida < 0) objetivo->vida = 0;
    std::cout << nombre << " ataca a " << objetivo->nombre << " por " << ataque << "\n";
}

void Personaje::habilidadEspecial(Personaje *objetivo) {
    if (!estaVivo() || !objetivo) return;
    objetivo->vida -= ataque * 2;
    if (objetivo->vida < 0) objetivo->vida = 0;
    std::cout << nombre << " usa habilidad especial en " << objetivo->nombre << "\n";
}

bool Personaje::agregarObjeto(ObjetoMagico *obj) {
    if (objetos.size() >= 2) return false;
    objetos.push_back(obj);
    return true;
}

void Personaje::usarObjeto(int index, Personaje *objetivo) {
    if (index < 0 || index >= objetos.size()) return;
    objetos[index]->usar(objetivo);
    if (objetos[index]->getUsos() <= 0) {
        delete objetos[index];
        objetos.erase(objetos.begin() + index);
    }
}

void Guerrero::habilidadEspecial(Personaje *objetivo) {
    if (!estaVivo() || !objetivo) return;
    objetivo->vida -= (ataque + 5);
    if (objetivo->vida < 0) objetivo->vida = 0;
    std::cout << nombre << " ejecuta golpazo\n";
}

void Mago::habilidadEspecial(Personaje *objetivo) {
    if (!estaVivo() || !objetivo) return;
    objetivo->vida -= (ataque + 8);
    if (objetivo->vida < 0) objetivo->vida = 0;
    std::cout << nombre << " lanza hechizo\n";
}

void Sanador::habilidadEspecial(Personaje *objetivo) {
    if (!estaVivo() || !objetivo) return;
    objetivo->vida += 10;
    std::cout << nombre << " cura a " << objetivo->nombre << "\n";
}
