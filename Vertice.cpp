#include "Vertice.h"

Vertice::Vertice(string nombre){
    this->nombre = nombre;
}

Vertice::~Vertice(){
    sig = 0;
    ady = 0;
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
