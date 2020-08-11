#include "Arista.h"

Arista::Arista(Vuelo * viaje){
    this->viaje = viaje;
}

Arista * Arista::get_arista(){
    return this->sig;
}

void Arista::set_sig_arista(Arista * siguiente){
    this->sig = siguiente;
}

Vertice * Arista::get_adyacente(){
    return this->ady;
}

void Arista::set_sig_adyacente(Vertice * adyacente){
    this->ady = adyacente;
}

void Arista::set_origen(string origen){
    this->origen = origen;
}

string Arista::get_origen(){
    return this->origen;
}
int Arista::get_precio(){
    return this->viaje->get_precio();
}

int Arista::get_tiempo(){
    return this->viaje->get_tiempo();
}