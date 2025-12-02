#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_MAGO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_MAGO_H

#include "Personaje.h" //heredar los atributos de personaje

class Mago : public Personaje {
public:
    Mago(string n, int nv, int v, int a, int d);
    void realizarAccion(Personaje* objetivo) override;       // recibe los datos de los atributos y los envia al constructor de personaje
                                                            // le da su habilidad unica con el override
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_MAGO_H