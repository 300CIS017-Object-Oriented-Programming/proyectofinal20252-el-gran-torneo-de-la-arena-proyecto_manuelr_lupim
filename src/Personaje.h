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
    Personaje(string n, int nv, int v, int a, int d, string r); //constructor en el q se dan todos los valores inciales para cada personaje, en cada atributo
    virtual ~Personaje(); // *DESTRUCTOR IMPORTANTE* para que al borrar un Personaje* que apunta a un Guerrero o Mago se llame el destructor correcto.

    // Getters - Todos retornan la información del personaje, estaVivo() devuelve true si la vida > 0.
    string getNombre() const;
    int getNivel() const;
    int getVida() const;
    int getAtaque() const;
    int getDefensa() const;
    string getRol() const;
    bool estaVivo() const;

    // Setters - Permiten modificar atributos, pero de forma controlada (setVida tiene sus límite).
    void setVida(int v);
    void setAtaque(int a);
    void setDefensa(int d);

    // Metodos virtuales
    virtual void realizarAccion(Personaje* objetivo) = 0; // Obliga a cada hijo a implementar su propia forma de atacar o actuar.
    virtual void mostrarInfo() const; //ps muestra la info que se le pida de x personaje

    void recibirDanio(int danio); // le va quitando "vida" al personaje
    void curar(int cantidad); // sube la vida sin pasa el maximo ya establecido
    void recibirDanioDirecto(int cantidad); //sirve para utilizar la daga sombria
};
#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_PERSONAJE_H