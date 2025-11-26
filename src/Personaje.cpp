#include "Personaje.h"
#include <iostream>

using std::endl;
using std::cout;

Personaje::Personaje(string n, int nv, int v, int a, int d, string r)
    : nombre(n), nivel(nv), vida(v), vidaMaxima(v), ataque(a), defensa(d), rol(r) {}

Personaje::~Personaje() {}

string Personaje::getNombre() const { return nombre; }
int Personaje::getNivel() const { return nivel; }
int Personaje::getVida() const { return vida; }
int Personaje::getAtaque() const { return ataque; }
int Personaje::getDefensa() const { return defensa; }
string Personaje::getRol() const { return rol; }
bool Personaje::estaVivo() const { return vida > 0; }

void Personaje::setVida(int v) {
    vida = v;
    if (vida > vidaMaxima) vida = vidaMaxima;
}

void Personaje::setAtaque(int a) { ataque = a; }
void Personaje::setDefensa(int d) { defensa = d; }

void Personaje::recibirDanio(int danio) {
    int danioReal = danio - defensa;
    if (danioReal < 0) danioReal = 0;
    vida -= danioReal;
    if (vida < 0) vida = 0;
}

void Personaje::curar(int cantidad) {
    vida += cantidad;
    if (vida > vidaMaxima) vida = vidaMaxima;
}

void Personaje::recibirDanioDirecto(int cantidad) {
    this->vida -= cantidad;
    if (this->vida < 0) this->vida = 0;
}

void Personaje::mostrarInfo() const {
    cout << "Nombre: " << nombre << " | Rol: " << rol
         << " | Nivel: " << nivel << " | Vida: " << vida
         << "/" << vidaMaxima << " | Ataque: " << ataque
         << " | Defensa: " << defensa << endl;
}
