#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_HEROE_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_HEROE_H

#include "Personaje.h"
#include "ObjetoMagico.h"
#include <vector>

class Heroe : public Personaje {
protected:
    std::vector<ObjetoMagico*> objetos; // máximo 2
public:
    Heroe(int id, const std::string &nombre, int nivel, int vida, int ataque, int defensa);
    virtual ~Heroe();
    bool asignarObjeto(ObjetoMagico* obj); // devuelve false si ya tiene 2
    bool retirarObjeto(int index); // devuelve true si retirado
    void usarObjeto(int index, Personaje *objetivo); // aplica y borra el objeto si se consume
    virtual void atacar(Personaje *objetivo) override;
    virtual std::string tipo() const override { return "Heroe"; }
    void listarObjetos() const;
};

class Guerrero : public Heroe {
public:
    Guerrero(int id, const std::string &nombre);
    virtual void atacar(Personaje *objetivo) override; // golpe fuerte
    virtual std::string tipo() const override { return "Guerrero"; }
};

class Mago : public Heroe {
public:
    Mago(int id, const std::string &nombre);
    virtual void atacar(Personaje *objetivo) override; // ataque mágico
    virtual std::string tipo() const override { return "Mago"; }
};

class Sanador : public Heroe {
public:
    Sanador(int id, const std::string &nombre);
    void curarAliado(Heroe *aliado);
    virtual std::string tipo() const override { return "Sanador"; }
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_HEROE_H