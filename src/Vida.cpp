#include "Vida.h"

Vida::Vida()
{
    //ctor

}

Vida::Vida(int edadmaxl)
{
    //ctor
    edadmax=edadmaxl;
}

Vida::~Vida()
{
    //dtor
}
//El vector
void Especie::imprimir(std::ostream &out) const {
    out << "Edad: " << edadmax
        << ", Tamano: " << tamano
        << " cm, Peso: " << peso
        << " kg, Genero: " << genero
        << ", Alimentacion: " << alimentacion;
}
