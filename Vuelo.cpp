#include "Vuelo.h"

Vuelo :: Vuelo(int precio, float tiempo){
    this->precio = precio;
    this->tiempo = tiempo;
}

Vuelo :: Vuelo(){
	this->precio = 0;
	this->tiempo = 0;
}

void Vuelo :: set_precio(int precio){
    this->precio = precio;
}

int Vuelo :: get_precio(){
    return this->precio;
}

void Vuelo :: set_tiempo(float tiempo){
    this->tiempo = tiempo;
}

float Vuelo :: get_tiempo(){
    return this->tiempo;
}
