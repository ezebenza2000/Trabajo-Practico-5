#include "Arista.h"

Arista::Arista(Vuelo * viaje){
    this->viaje = viaje;
}

Arista::~Arista(){
    sig = 0;
    ady = 0;
    viaje = 0;
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
float Arista::get_precio(){
    return this->viaje->get_precio();
}

float Arista::get_tiempo(){
    return this->viaje->get_tiempo();
}
