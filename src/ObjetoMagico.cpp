#include "ObjetoMagico.h"
#include "Personaje.h"
#include <iostream>

ObjetoMagico::ObjetoMagico(const std::string &n, int u) : nombre(n), usos(u) {}
ObjetoMagico::~ObjetoMagico() {}

const std::string& ObjetoMagico::getNombre() const { return nombre; }
int ObjetoMagico::getUsos() const { return usos; }

void ObjetoMagico::usar(Personaje *objetivo) {
    if (!objetivo || usos <= 0) return;
    objetivo->habilidadEspecial(objetivo);
    usos--;
    std::cout << nombre << " usado, quedan " << usos << "\n";
}
