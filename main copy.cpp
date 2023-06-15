#include <iostream>
#include"navios.h"
#include"destructor.h"
#include"submarino.h"
#include"oficial.h"
#include "flota.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    cout<<"DESPLIEGUE EXAMEN FNAL"<<endl;
    Destructor ussstar("D1","USS Star",100,5);
    Destructor ussfalcon("D2","USS Falcon",200,10);
    Submarino ussfoca("S1","USS Foca",50,5);
    Submarino ussfish("S2","USS Fish",100,2);
    Oficial oficial(12,"John","General");
    Flota flota(124,oficial);
    flota.agregarNavio(&ussstar);
    flota.agregarNavio(&ussfalcon);
    flota.agregarNavio(&ussfoca);
    flota.agregarNavio(&ussfish);
    flota.displayFlota();
    flota.displayDestructores();
    flota.getPoderTotalFuego();

    return 0;
}