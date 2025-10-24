#include "Venado.h"

Venado::Venado(){

}

Venado::Venado(string nombrel, int v, float tamano, string alimentacion, string genero, float peso): Especie( v, tamano, alimentacion, genero, peso)
{
    //ctor
    nombre= nombrel;
}

ostream& operator << (ostream &out, const Venado &deer){
    out<< "El nombre del venado es "<< deer.nombre <<endl;
    out<< "Su tamano es "<<deer.tamano<<", su edad es "<<deer.edadmax<< " y su peso es de "<<deer.peso<<endl;
    out<< "El genero del venado es "<< deer.genero << "Y se alimenta de "<< deer.alimentacion <<endl;
    return out;
}

istream& operator>>(istream &in, Venado &deer){
cout<<"Dame un nombre para el venado: "<<endl;
in>>deer.nombre;
try{
cout<<"Dame edad: "<< endl;
in>>deer.edadmax;
if(deer.edadmax>20){
    throw invalid_argument("La edad de un venado no puede ser mayor a 20 anios");
}
if(deer.edadmax<0){
    throw invalid_argument("La edad debe ser positiva");
}
}
catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}
try{
cout<<"Dame el tamano en centimetros: "<<endl;
in>>deer.tamano;
if(deer.tamano>210){
    throw invalid_argument("Los venados no miden mas de 210 cm");
}
if(deer.tamano<45){
    throw invalid_argument("Los venados no miden menos de 45 cm");
}
}
catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}
try{
cout<<"Que tipo de alimento come (carne o vegetales): "<<endl;
in>>deer.alimentacion;
if(deer.alimentacion!= "carne" || deer.alimentacion!= "vegetales"){
    throw invalid_argument("Vuelve a escribir");
}
}
catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}
try{
cout<<"De que genero es(macho o hembra): "<<endl;
in>>deer.genero;
if(deer.genero!= "macho" || deer.genero!= "hembra"){
    throw invalid_argument("Vuelva a escribir");
}
}
catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}
try{
cout<<"Dame el peso del venado kg: "<<endl;
in>>deer.peso;
if(deer.peso>180){
    throw invalid_argument("Es muy pesado para un venado");
}
if(deer.peso<40){
    throw invalid_argument("Es muy delgado para un venado");
}
}
catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}
return in;
}

Venado Venado::operator+(Venado &deer) {
    Venado tmp;
    tmp.edadmax = edadmax + deer.edadmax;
    tmp.tamano  = tamano + deer.tamano;
    tmp.peso    = peso + deer.peso;
    return tmp;
}

Venado Venado::operator-(Venado &deer) {
    Venado tmp;
    tmp.edadmax = edadmax - deer.edadmax;
    tmp.tamano  = tamano - deer.tamano;
    tmp.peso    = peso - deer.peso;
    return tmp;
}

Venado Venado::operator*(Venado &deer) {
    Venado tmp;
    tmp.edadmax = edadmax * deer.edadmax;
    tmp.tamano  = tamano * deer.tamano;
    tmp.peso    = peso * deer.peso;
    return tmp;
}

Venado Venado::operator/(Venado &deer) {
    Venado tmp;
    tmp.edadmax = edadmax / deer.edadmax;
    tmp.tamano  = tamano / deer.tamano;
    tmp.peso    = peso / deer.peso;
    return tmp;
}


Venado::~Venado()
{
    //dtor
}
