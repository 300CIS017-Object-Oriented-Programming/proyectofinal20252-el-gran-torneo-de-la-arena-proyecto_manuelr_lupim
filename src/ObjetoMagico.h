#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_OBJETOMAGICO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_OBJETOMAGICO_H

#include <string>

class Personaje;

class ObjetoMagico {
public:
    ObjetoMagico(const std::string &nombre, int usos);
    virtual ~ObjetoMagico();

    const std::string& getNombre() const;
    int getUsos() const;

    virtual void usar(Personaje *objetivo);

protected:
    std::string nombre;
    int usos;
};
#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_OBJETOMAGICO_H