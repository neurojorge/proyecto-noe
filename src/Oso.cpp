#include "Oso.h"

Oso::Oso(){

}

Oso::Oso(string nombrel, int v, float tamano, string alimentacion, string genero, float peso): Especie( v, tamano, alimentacion, genero, peso)
{
    //ctor
    nombre= nombrel;
}

ostream& operator << (ostream &out, const Oso &bear){
    out<< "El nombre del oso es "<< bear.nombre <<endl;
    out<< "Su tamano es "<<bear.tamano<<", su edad es "<<bear.edadmax<< " y su peso es de "<<bear.peso<<endl;
    out<< "El genero del oso es "<< bear.genero << "Y se alimenta de "<< bear.alimentacion <<endl;
    return out;
}

istream& operator>>(istream &in, Oso &bear) {
cout << "Dame un nombre para el oso: " << endl;
in >> bear.nombre;
try {
cout << "Dame edad: " << endl;
in >> bear.edadmax;
if (bear.edadmax > 20) {
throw invalid_argument("La edad de un oso no puede ser mayor a 20 anos");
}
if (bear.edadmax < 0) {
throw invalid_argument("La edad debe ser positiva");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
try {
cout << "Dame el tamano en centimetros: " << endl;
in >> bear.tamano;
if (bear.tamano > 210) {
throw invalid_argument("Los osos no miden mas de 210 cm");
}
if (bear.tamano < 45) {
throw invalid_argument("Los osos no miden menos de 45 cm");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
try {
cout << "Que tipo de alimento come (carne o vegetales)?: " << endl;
in >> bear.alimentacion;
if (bear.alimentacion != "carne" || bear.alimentacion != "vegetales") {
throw invalid_argument("Vuelve a escribir 'carne' o 'vegetales'");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
try {
cout << "De que genero es (macho o hembra)?: " << endl;
in >> bear.genero;
if (bear.genero != "macho" || bear.genero != "hembra") {
throw invalid_argument("Vuelve a escribir 'macho' o 'hembra'");
}
}
catch (const exception& e) {
cout<< "Error: " << e.what() << endl;
}
try {
cout << "Dame el peso del oso (kg): " << endl;
in >> bear.peso;
if (bear.peso > 180) {
throw invalid_argument("Es muy pesado para un oso");
}
if (bear.peso < 40) {
throw invalid_argument("Es muy delgado para un oso");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
return in;
}


Oso Oso::operator+(Oso &bear)  {
    Oso tmp;
    tmp.edadmax= edadmax +bear.edadmax;
    tmp.tamano= tamano+ bear.tamano;
    tmp.peso= peso + bear.peso;
    return tmp;
}
Oso Oso::operator-(Oso &bear)  {
    Oso tmp;
    tmp.edadmax= edadmax -bear.edadmax;
    tmp.tamano= tamano - bear.tamano;
    tmp.peso= peso - bear.peso;
    return tmp;
}
Oso Oso::operator*(Oso &bear)  {
    Oso tmp;
    tmp.edadmax= edadmax*bear.edadmax;
    tmp.tamano= tamano* bear.tamano;
    tmp.peso= peso * bear.peso;
    return tmp;
}
Oso Oso::operator/(Oso &bear)  {
    Oso tmp;
    tmp.edadmax= edadmax/bear.edadmax;
    tmp.tamano= tamano / bear.tamano;
    tmp.peso= peso /  bear.peso;
    return tmp;
}



Oso::~Oso()
{
    //dtor
}
