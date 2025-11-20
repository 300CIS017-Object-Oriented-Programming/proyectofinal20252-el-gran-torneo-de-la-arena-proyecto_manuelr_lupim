#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_PERSONAJE_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_PERSONAJE_H

#include <string>
#include <vector>

class ObjetoMagico;

class Personaje {
public:
    Personaje(int id, const std::string &nombre, int vida, int ataque, const std::string &tipo);
    virtual ~Personaje();

    int getId() const;
    const std::string& getNombre() const;
    int getVida() const;
    bool estaVivo() const;

    virtual void atacar(Personaje *objetivo);
    virtual void habilidadEspecial(Personaje *objetivo);

    bool agregarObjeto(ObjetoMagico *obj);
    void usarObjeto(int index, Personaje *objetivo);

protected:
    int id;
    std::string nombre;
    int vida;
    int ataque;
    std::string tipo;
    std::vector<ObjetoMagico*> objetos;
};

class Guerrero : public Personaje {
public:
    using Personaje::Personaje;
    void habilidadEspecial(Personaje *objetivo) override;
};

class Mago : public Personaje {
public:
    using Personaje::Personaje;
    void habilidadEspecial(Personaje *objetivo) override;
};

class Sanador : public Personaje {
public:
    using Personaje::Personaje;
    void habilidadEspecial(Personaje *objetivo) override;
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_PERSONAJE_H