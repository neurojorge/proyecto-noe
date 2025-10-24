#ifndef OSO_H
#define OSO_H
#include "Especie.h"


class Oso: public Especie
{
    public:
        string nombre;
        Oso();
        Oso(string nombre, int v, float tamano, string alimentacion, string genero, float peso);
        virtual ~Oso();


        friend ostream& operator << (ostream&, const Oso&);
        friend istream& operator >> (istream&, Oso&);

        Oso operator+(Oso&);
        Oso operator-(Oso&);
        Oso operator*(Oso&);
        Oso operator/(Oso&);


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

#endif // OSO_H
