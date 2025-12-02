#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUERRERO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUERRERO_H

#include "Personaje.h"

//hereda to.do de personaje MENOS el nuevo metodo
class Guerrero : public Personaje {
private:
    float probabilidadCritico; //nuevo metodo que solo el puede usar y lo diferencia de los demas

public:
    Guerrero(string n, int nv, int v, int a, int d);
    void realizarAccion(Personaje* objetivo) override;  //"OVERRIDE" para saber que va a cambiar, aunque hacen cosas parecidas
};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUERRERO_H