#ifndef NAVIOS_H
#define NAVIOS_H
#include <iostream>
#include <string>
#include <vector>
#include "oficial.h"

using std::ostream;
using std::string;
using std::vector;

class Navios{
    protected:
        string idNavios;
        string nombre;
        double poderFuego;
    public:
        Navios();
        Navios(string id, string nom, double poder);
        virtual double getPoderFuego()=0;
};



#endif