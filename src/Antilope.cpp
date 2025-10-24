#include "Antilope.h"
Antilope::Antilope(){

}
Antilope::Antilope(string nombrel, int v, float tamano, string alimentacion, string genero, float peso): Especie( v, tamano, alimentacion, genero, peso)
{
    //ctor
     nombre= nombrel;
}

ostream& operator << (ostream &out, const Antilope &anti){
    out<< "El nombre del antilope es "<< anti.nombre <<endl;
    out<< "Su tamano es "<<anti.tamano<<", su edad es "<<anti.edadmax<< " y su peso es de "<<anti.peso<<endl;
    out<< "El genero del antilope es "<< anti.genero << "Y se alimenta de "<< anti.alimentacion <<endl;
    return out;
}

istream& operator>>(istream &in, Antilope &anti) {
cout << "Dame un nombre para el antilope: " << endl;
in >> anti.nombre;

try {
cout << "Dame edad: " << endl;
in >> anti.edadmax;
if (anti.edadmax > 20) {
throw invalid_argument("La edad de un antilope no puede ser mayor a 20 anos");
}
if (anti.edadmax <= 0) {
throw invalid_argument("La edad debe ser positiva");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
try {
cout << "Dame el tamano en centimetros: " << endl;
in >> anti.tamano;
if (anti.tamano > 210) {
throw invalid_argument("Los antilopes no miden mas de 210 cm");
}
if (anti.tamano < 45) {
throw invalid_argument("Los antilopes no miden menos de 45 cm");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
try {
cout << "Que tipo de alimento come (carne o vegetales)?: " << endl;
in >> anti.alimentacion;
if (anti.alimentacion != "carne" || anti.alimentacion != "vegetales") {
throw invalid_argument("Vuelve a escribir 'carne' o 'vegetales'");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
try {
cout << "¿De qué genero es (macho o hembra)?: " << endl;
in >> anti.genero;
if (anti.genero != "macho" || anti.genero != "hembra") {
throw invalid_argument("Vuelve a escribir 'macho' o 'hembra'");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
try {
cout << "Dame el peso del antilope (kg): " << endl;
in >> anti.peso;
if (anti.peso > 180) {
throw invalid_argument("Es muy pesado para un antilope");
}
if (anti.peso < 40) {
throw invalid_argument("Es muy delgado para un antilope");
}
}
catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
return in;
}


Antilope Antilope::operator+(Antilope &anti)  {
    Antilope tmp;
    tmp.edadmax= edadmax +anti.edadmax;
    tmp.tamano= tamano+ anti.tamano;
    tmp.peso= peso + anti.peso;
    return tmp;
}
Antilope Antilope::operator-(Antilope &anti)  {
    Antilope tmp;
    tmp.edadmax= edadmax -anti.edadmax;
    tmp.tamano= tamano - anti.tamano;
    tmp.peso= peso - anti.peso;
    return tmp;
}
Antilope Antilope::operator*(Antilope &anti)  {
    Antilope tmp;
    tmp.edadmax= edadmax*anti.edadmax;
    tmp.tamano= tamano* anti.tamano;
    tmp.peso= peso * anti.peso;
    return tmp;
}
Antilope Antilope::operator/(Antilope &anti)  {
    Antilope tmp;
    tmp.edadmax= edadmax/anti.edadmax;
    tmp.tamano= tamano / anti.tamano;
    tmp.peso= peso /  anti.peso;
    return tmp;
}

Antilope::~Antilope()
{
    //dtor
}
