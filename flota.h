#ifndef FLOTA_H
#define FLOTA_H
#include <iostream>
#include <string>
#include <vector>
#include "oficial.h"
#include "navios.h"

using std::ostream;
using std::string;
using std::vector;

class Flota{
    private:
        int idFlota;
        Oficial oficial;
        vector <Navios*> barcos;
    public:
        Flota(int id, Oficial of);
        double getPoderTotalFuego();
        void agregarNavio(Navios *n);
        void displayFlota();
        void displayDestructores();
};



#endif