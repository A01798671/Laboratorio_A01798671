#include <iostream>
#include <string>
#include "destructor.h"

using std::ostream;
using std::string;
using std::endl;

Destructor::Destructor(string id, string nom, double pod, int nca){
    idNavios=id;
    nombre=nom;
    poderFuego=pod;
    numCanones=nca;
}

ostream & operator<<(ostream &COUT, Destructor &d){
    COUT << "Destructor: "<<d.nombre<<"y tengo un poder de fuego de:"<<d.poderFuego<<endl;
    return COUT;
}

double Destructor::getPoderFuego(){
    double Poder;
    Poder=poderFuego*numCanones;
    return Poder;
}

