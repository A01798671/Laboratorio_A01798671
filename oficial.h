#ifndef OFICIAL_H
#define OFICIAL_H
#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Oficial{
    private:
        int noIdentificacion;
        string nombre;
        string rango;
    public:
        Oficial();
        Oficial(int id, string nom, string ran);
        friend ostream & operator<<(ostream &COUT,Oficial &o);
};



#endif