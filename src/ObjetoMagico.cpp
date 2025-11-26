#include "ObjetoMagico.h"
#include "Personaje.h"
#include <iostream>
using std::cout;
using std::endl;



ObjetoMagico::ObjetoMagico(string n, string desc, int s)
    : nombre(n), descripcion(desc), stock(s) {}

ObjetoMagico::~ObjetoMagico() {}

string ObjetoMagico::getNombre() const { return nombre; }
string ObjetoMagico::getDescripcion() const { return descripcion; }
int ObjetoMagico::getStock() const { return stock; }

void ObjetoMagico::decrementarStock() {
    if (stock > 0) stock--;
}

void ObjetoMagico::incrementarStock() {
    stock++;
}

void ObjetoMagico::mostrarInfo() const {
    cout << "- " << nombre << ": " << descripcion
         << " (Stock: " << stock << ")" << endl;
}
