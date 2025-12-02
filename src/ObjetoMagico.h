#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_OBJETOMAGICO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_OBJETOMAGICO_H

#include <string>
#include "Personaje.h"
using std::string;

class ObjetoMagico {
protected:
    string nombre;
    string descripcion;
    int stock;

public:
    ObjetoMagico(string n, string desc, int s);
    virtual ~ObjetoMagico();

    string getNombre() const;
    string getDescripcion() const;
    int getStock() const;
    void decrementarStock();
    void incrementarStock();

    virtual void usar(Personaje* objetivo) = 0;  //classe abstracta, cada clase debe definir esto
    virtual void mostrarInfo() const;
};
#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_OBJETOMAGICO_H