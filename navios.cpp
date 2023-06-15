#include <iostream>
#include <string>
#include "navios.h"

using std::ostream;
using std::string;
using std::endl;

Navios::Navios(){

}

Navios::Navios(string id, string nom, double poder){
    idNavios=id;
    nombre=nom;
    poderFuego=poder;
}

double Navios::getPoderFuego(){
    
}