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

void ObjetoMagico::decrementarStock() {      //si el estock es un numero positivo le resta1
    if (stock > 0) stock--;
}

void ObjetoMagico::incrementarStock() {        //es un metodo para aumentar en uno el stock
    stock++;
}

void ObjetoMagico::mostrarInfo() const {      //muestra la informacion del objeto en cuestion
    cout << "- " << nombre << ": " << descripcion
         << " (Stock: " << stock << ")" << endl;
}
