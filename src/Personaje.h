#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_PERSONAJE_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_PERSONAJE_H

#include <string> //Libreria para no tener que escribir std::string to.do el rato
using std::string;


class Personaje {
protected:          //protected para que solo las clases hijas puedan acceder
    string nombre;
    int nivel;
    int vida;
    int vidaMaxima;
    int ataque;
    int defensa;
    string rol;

public:
    Personaje(string n, int nv, int v, int a, int d, string r);
    virtual ~Personaje();

    // Getters
    string getNombre() const;
    int getNivel() const;
    int getVida() const;
    int getAtaque() const;
    int getDefensa() const;
    string getRol() const;
    bool estaVivo() const;

    // Setters
    void setVida(int v);
    void setAtaque(int a);
    void setDefensa(int d);

    // Metodos virtuales
    virtual void realizarAccion(Personaje* objetivo) = 0;
    virtual void mostrarInfo() const;

    void recibirDanio(int danio);
    void curar(int cantidad);
    void recibirDanioDirecto(int cantidad); //sirve para utilizar la daga sombria
};
#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_PERSONAJE_H