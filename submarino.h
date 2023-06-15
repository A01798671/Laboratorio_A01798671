#ifndef SUBMARINO_H
#define SUBMARINO_H
#include <iostream>
#include <string>
#include "navios.h"

using std::ostream;
using std::string;

class Submarino: public Navios{
    private:
        int numCanones;
    public:
        Submarino(string id, string nom, double pod, int nca);
        double getPoderFuego();
        friend ostream & operator<<(ostream &COUT,Submarino &s);
};



#endif