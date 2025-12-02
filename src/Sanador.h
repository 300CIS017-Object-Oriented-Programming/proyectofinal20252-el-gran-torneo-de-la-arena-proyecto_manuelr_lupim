#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_SANADOR_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_SANADOR_H

#include "Personaje.h"
#include <vector>
using std::vector;

class Sanador : public Personaje {
public:
    Sanador(string n, int nv, int v, int a, int d);
    void realizarAccion(Personaje* objetivo) override;
    void curarAliado(vector<Personaje*>& aliados);  //es el metodo para poder curar a un aliado dentro de los personajes de la guild
};



#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_SANADOR_H