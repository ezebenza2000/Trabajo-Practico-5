#include "Vuelo.h"

Vuelo :: Vuelo(int precio, int tiempo){
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

void Vuelo :: set_tiempo(int tiempo){
    this->tiempo = tiempo;
}

int Vuelo :: get_tiempo(){
    return this->tiempo;
}