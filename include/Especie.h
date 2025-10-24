#ifndef ESPECIE_H
#define ESPECIE_H
#include "Vida.h"
#include <string>
#include <iostream>

class Especie: public Vida
{
    public:
       Especie();
        Especie(int v, float tamano, string alimentacion, string genero, float peso);
        virtual ~Especie();

    protected:
        float tamano;
        string alimentacion;
        string genero;
        float peso;
    private:

};

#endif // ESPECIE_H
