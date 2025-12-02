#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_DAGASOMBRIA_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_DAGASOMBRIA_H


#include "ObjetoMagico.h"

class DagaSombria : public ObjetoMagico {      //Es un ObjetoMagico y puede usarse polimórficamente como ObjetoMagico*.
public:
    DagaSombria(int stock);                    // verifica que haya disponibles
    void usar(Personaje* objetivo) override;   // sobrescribe el méto.do virtual puro de ObjetoMagico
                                                //usar definirá el efecto específico de esta daga sobre un Personaje*.

};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_DAGASOMBRIA_H