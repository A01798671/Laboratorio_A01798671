#include <iostream>
#include <string>
#include "oficial.h"

using std::ostream;
using std::string;
using std::endl;

Oficial::Oficial(){

}

Oficial::Oficial(int id, string nom, string ran){
    noIdentificacion=id;
    nombre=nom;
    rango=ran;
}

ostream & operator<<(ostream &COUT, Oficial &o){
    COUT <<o.rango<<" "<<o.nombre<<",id: "<<o.noIdentificacion<<endl;
    return COUT;
}

