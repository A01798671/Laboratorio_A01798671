#include <iostream>
#include <string>
#include "submarino.h"

using std::ostream;
using std::string;
using std::endl;

Submarino::Submarino(string id, string nom, double pod, int nca){
    idNavios=id;
    nombre=nom;
    poderFuego=pod;
    numCanones=nca;
}

ostream & operator<<(ostream &COUT, Submarino &s){
    COUT << "Submarino: "<<s.nombre<<"y tengo un poder de fuego de:"<<s.poderFuego<<endl;
    return COUT;
}

double Submarino::getPoderFuego(){
    double Poder;
    Poder=poderFuego*numCanones;
    return Poder;
}

