#ifndef ANTILOPE_H
#define ANTILOPE_H
#include "Especie.h"

class Antilope: public Especie
{
    public:
        string nombre;
        Antilope();
        Antilope(string nombre, int v, float tamano, string alimentacion, string genero, float peso);
        virtual ~Antilope();


        friend ostream& operator << (ostream&, const Antilope&);
        friend istream& operator >> (istream&, Antilope&);

        Antilope operator+(Antilope&);
        Antilope operator-(Antilope&);
        Antilope operator*(Antilope&);
        Antilope operator/(Antilope&);

        float gettamano() const{
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

#endif // ANTILOPE_H
