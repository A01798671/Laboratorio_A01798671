#include <iostream>
#include <string>
#include "flota.h"
#include "destructor.h"
#include "submarino.h"

using std::ostream;
using std::string;
using std::endl;
using std::cout;

Flota::Flota(int id, Oficial of){
    idFlota=id;
    oficial=of;
}

double Flota::getPoderTotalFuego(){
    double poder_total_fuego = 0.0;
    for (auto& barco : barcos){
        poder_total_fuego += barco->getPoderFuego();
    }
    return poder_total_fuego;
}

void Flota::agregarNavio(Navios *n){
    barcos.push_back(n);
}

void Flota::displayFlota(){
    cout << "La flota: " << idFlota << ", comandada por el oficial: "<<oficial<<" consta de los siguientes barcos:" << endl;
    for (auto& barco : barcos){
        Destructor* destructor = dynamic_cast<Destructor*>(barco);
        if (destructor != nullptr){
            cout << *destructor;
        }
        Submarino* submarino = dynamic_cast<Submarino*>(barco);
        if (submarino != nullptr){
            cout << *submarino;
        }
    }
    double Ptotal=getPoderTotalFuego();
    cout<<"El poder total de la flota es de: "<<Ptotal<<endl;
}

void Flota::displayDestructores(){
    cout << "Destructores en la flota " << idFlota << ":" << endl;
    for (auto& barco : barcos){
        Destructor* destructor = dynamic_cast<Destructor*>(barco);
        if (destructor != nullptr){
            cout << *destructor;
        }
    }
}
