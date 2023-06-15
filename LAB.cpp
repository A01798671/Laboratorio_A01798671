//main.cpp
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


//oficial.h
#ifndef OFICIAL_H
#define OFICIAL_H
#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Oficial{
    private:
        int noIdentificacion;
        string nombre;
        string rango;
    public:
        Oficial();
        Oficial(int id, string nom, string ran);
        friend ostream & operator<<(ostream &COUT,Oficial &o);
};



#endif


//oficial.cpp
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

//flota.h
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


//flota.cpp
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


//navios.h
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

//navios.cpp
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

//destructor.h
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

//destructor.cpp
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

//submarino.h
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

//submarino.cpp
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

