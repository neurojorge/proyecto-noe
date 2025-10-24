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

    protected:
        int edadmax;
        bool estado;
    private:

};

#endif // VIDA_H
