#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
#include <iostream>
#include "Arista.h"
using namespace std;



class Vertice{
  private:
    Vertice *sig; //sig representa el vertice que le sigue en la lista.
    Arista *ady;  //ady reprenseta su primer arista adyacente.
    string nombre;
  public:
    Vertice (string nombre);
    void set_sig_vertice(Vertice * siguiente);
    Vertice * get_sig_vertice();
    void set_adyacente(Arista * adyacente);
    Arista * get_adyacente();
    void set_nombre(string nombre);
    string get_nombre();
};

Vertice::Vertice(string nombre){
    this->nombre = nombre;
}

void Vertice::set_sig_vertice(Vertice * siguiente){
    this->sig = siguiente;
}

Vertice * Vertice::get_sig_vertice(){
    return this->sig;
}

void Vertice::set_adyacente(Arista * adyacente){
    this->ady = adyacente;
}

Arista * Vertice::get_adyacente(){
    return this->ady;
}

void Vertice::set_nombre(string nombre){
    this->nombre = nombre;
}

string Vertice::get_nombre(){
    return this->nombre;
}

#endif // VERTICE_H_INCLUDED
