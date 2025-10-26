#include "Oso.h"
#include "Antilope.h"
#include "Venado.h"

// Oso
void Oso::imprimir(std::ostream &out) const {
    out << "[Oso] Nombre: " << nombre << " - ";
    Especie::imprimir(out);
    out << std::endl;
}
Vida* Oso::clone() const { return new Oso(*this); }

// Antilope
void Antilope::imprimir(std::ostream &out) const {
    out << "[Antilope] Nombre: " << nombre << " - ";
    Especie::imprimir(out);
    out << std::endl;
}
Vida* Antilope::clone() const { return new Antilope(*this); }

// Venado
void Venado::imprimir(std::ostream &out) const {
    out << "[Venado] Nombre: " << nombre << " - ";
    Especie::imprimir(out);
    out << std::endl;
}
Vida* Venado::clone() const { return new Venado(*this); }

