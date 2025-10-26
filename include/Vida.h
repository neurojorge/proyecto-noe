#ifndef VIDA_H
#define VIDA_H
#include <string>
#include <iostream>
using namespace std;

class Vida
{
    public:
        Vida();
        Vida(int edadmax);
        virtual ~Vida();
        //polimorfismo método para impresión
        virtual void imprimir(std::ostream &out) const = 0;

        //Copiar objetos polimorficos
        virtual Vida* clone() const = 0;


    protected:
        int edadmax;
        bool estado;
    private:

};

#endif // VIDA_H
