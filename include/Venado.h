#ifndef VENADO_H
#define VENADO_H
#include "Especie.h"

class Venado: public Especie
{
    public:
        string nombre;
        Venado();
        Venado(string nombre, int v, float tamano, string alimentacion, string genero, float peso);
        virtual ~Venado();

        friend ostream& operator << (ostream&, const Venado&);
        friend istream& operator >> (istream&, Venado&);

        Venado operator+(Venado&);
        Venado operator-(Venado&);
        Venado operator*(Venado&);
        Venado operator/(Venado&);


        int gettamano() const{
        return tamano;
        }
        void settamano(int Nuevotamano){
        tamano= Nuevotamano;
        }
        string getalimentacion()const {
        return alimentacion;
        }
        void setalimentacion(string Nuevaalimentacion){
        alimentacion=Nuevaalimentacion;
        }
        string getgenero()const {
        return genero;
        }
        void setgenero(string Nuevogenero){
        genero=Nuevogenero;
        }
        float getpeso()const {
        return peso;
        }
        void setpeso(float Nuevopeso){
        peso=Nuevopeso;
        }
    protected:

    private:
};

#endif // VENADO_H
