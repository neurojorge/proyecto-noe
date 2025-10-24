#include "Especie.h"

Especie::Especie(){

}
Especie::Especie(int v, float tamanol, string alimentacionl, string generol, float pesol): Vida(v)
{
    //ctor
    tamano=tamanol;
    alimentacion=alimentacionl;
    genero=generol;
    peso=pesol;
}

Especie::~Especie()
{
    //dtor
}
