#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H
#include <iostream>
#include <string>
#include "navios.h"

using std::ostream;
using std::string;

class Destructor: public Navios{
    private:  
        int numCanones;
    public:
        Destructor(string id, string nom, double pod, int nca);
        double getPoderFuego();
        friend ostream & operator<<(ostream &COUT,Destructor &d);
};



#endif